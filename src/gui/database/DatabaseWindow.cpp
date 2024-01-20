#include "DatabaseWindow.h"
#include "../../../ui/ui_databasewindow.h"

#include "../list/ListWindow.h"

#include <QFileDialog>

DatabaseWindow::DatabaseWindow(Database &database, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::DatabaseWindow),
    _database(&database)
{
    ui->setupUi(this);
}

DatabaseWindow::~DatabaseWindow() {
    delete ui;
    delete _database;
}

void DatabaseWindow::on_loadImageButton_clicked() {
    this->_imagePath = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "/home/", tr("Image Files (*.png *.jpg)"));
    ui->imagePathText->setText(this->_imagePath);
}

void DatabaseWindow::on_finishButton_clicked() {
    if(!(this->_imagePath.isEmpty() || ui->imageNameText->toPlainText().isEmpty() || ui->imageSourceText->toPlainText().isEmpty() || ui->imageSourceText->toPlainText().isEmpty() || ui->accessLevelText->toPlainText().isEmpty() || ui->imageCostText->toPlainText().isEmpty())) {
        this->_database->addImage(Image(ImageDescriptor((int) this->_database->getImages().size() + 1, this->_imagePath.toStdString(), ui->imageNameText->toPlainText().toStdString(),
                                        ui->imageSourceText->toPlainText().toStdString(), ui->imageAuthorText->toPlainText().toStdString(),
                                        ui->accessLevelText->toPlainText().toStdString(), std::stoi(ui->imageCostText->toPlainText().toStdString()))));
        emit imageAdded();
        this->close();
    }
}

void DatabaseWindow::on_returnButton_clicked() {
    this->close();
}
