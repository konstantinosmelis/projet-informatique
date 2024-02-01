#include "DatabaseWindow.h"
#include "../../../ui/ui_databasewindow.h"
#include "../list/ListWindow.h"
#include <QFileInfo>
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
}

void DatabaseWindow::imageLoadingHandler() {
    this->_imagePath = QFileDialog::getOpenFileName(this, tr("Choisir une image"), "/home/", tr("Image Files (*.png *.jpg)"));
    if(this->_imagePath.isEmpty())
        return;
    ui->imagePathText->setText(this->_imagePath);
    ui->imagePreview->setPixmap(QPixmap(this->_imagePath).scaledToWidth(ui->imageGroup->width()));
}

void DatabaseWindow::imageAddedHandler() {
    if(!(ui->imagePathText->text().isEmpty() || ui->imageNameText->text().isEmpty() || ui->imageSourceText->text().isEmpty() || ui->imageAuthorText->text().isEmpty() || ui->accessLevelText->currentText().isEmpty() || ui->imageCostText->text().isEmpty())) {
        this->_database->addImage(Image(ImageDescriptor((int) this->_database->getImages().size() + 1, ui->imagePathText->text().toStdString(), ui->imageNameText->text().toStdString(),
                                        ui->imageSourceText->text().toStdString(), ui->imageAuthorText->text().toStdString(),

                                                        ui->accessLevelText->currentText().toStdString(), std::stoi(ui->imageCostText->text().toStdString()))));

        QString myFile = QFileDialog::getSaveFileName(this, tr("Enregistrer le fichier"), "/home/", tr("Text File(*.txt)"));
        if(myFile.isEmpty())
            return;
        this->_database->getImageById((int) this->_database->getImages().size()).getImageDescriptor().save(myFile.toStdString());
        emit imageAdded();
        this->close();
    }
}

void DatabaseWindow::returnHandler() {
    this->close();
}
