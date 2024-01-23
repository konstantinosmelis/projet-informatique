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

    this->connect(ui->loadImageButton, &QPushButton::clicked, this, [=]() { this->imageLoadingHandler(); });
    this->connect(ui->finishButton, &QPushButton::clicked, this, [=]() { this->imageAddedHandler(); });
    this->connect(ui->returnButton, &QPushButton::clicked, this, [=]() { this->returnHandler(); });
}

DatabaseWindow::~DatabaseWindow() {
    delete ui;
    delete _database;
}

void DatabaseWindow::imageLoadingHandler() {
    this->_imagePath = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "/home/", tr("Image Files (*.png *.jpg)"));
    if(this->_imagePath.isEmpty())
        return;
    ui->imagePathText->setText(this->_imagePath);
    ui->imagePreview->setPixmap(QPixmap(this->_imagePath).scaledToWidth(ui->imageGroup->width()));
}

void DatabaseWindow::imageAddedHandler() {
    if(!(this->_imagePath.isEmpty() || ui->imageNameText->toPlainText().isEmpty() || ui->imageSourceText->toPlainText().isEmpty() || ui->imageSourceText->toPlainText().isEmpty() || ui->accessLevelText->toPlainText().isEmpty() || ui->imageCostText->toPlainText().isEmpty())) {
        this->_database->addImage(Image(ImageDescriptor((int) this->_database->getImages().size() + 1, this->_imagePath.toStdString(), ui->imageNameText->toPlainText().toStdString(),
                                        ui->imageSourceText->toPlainText().toStdString(), ui->imageAuthorText->toPlainText().toStdString(),
                                        ui->accessLevelText->toPlainText().toStdString(), std::stoi(ui->imageCostText->toPlainText().toStdString()))));
        emit imageAdded();
        this->close();
    }
}

void DatabaseWindow::returnHandler() {
    this->close();
}
