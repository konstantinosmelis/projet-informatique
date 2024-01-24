#include "ListWindow.h"
#include "../../../ui/ui_listwindow.h"

#include "../database/DatabaseWindow.h"
#include "../processing/ImageProcessingWindow.h"

#include <QFileDialog>
#include <QMessageBox>

ListWindow::ListWindow(const User &user, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ListWindow),
    _database()
{
    this->_user = user;
    ui->setupUi(this);

    if(!this->_user.isAdmin()) {
        ui->addImageButton->setEnabled(false);
        ui->imageProcessingButton->setEnabled(false);
    }

    this->connect(ui->selectDatabaseButton, &QPushButton::clicked, this, [=]() { this->selectDatabaseHandler(); });
    this->connect(ui->addImageButton, &QPushButton::clicked,this, [=]() { this->addImageHandler(); });
    this->connect(ui->imageProcessingButton, &QPushButton::clicked,this, [=]() { this->imageProcessingHandler(); });
    this->connect(ui->exitButton, &QPushButton::clicked,this, [=]() { this->exitHandler(); });
    this->connect(ui->databaseTable, &QTableWidget::cellClicked, this, [=](const int row) { this->imageDisplayHandler(row); });
}

ListWindow::~ListWindow() {
    delete ui;
}

void ListWindow::loadTable() const {
    int i;
    ui->databaseTable->setRowCount(0);
    for(const Image &image : this->_database.getImages()) {
        i = ui->databaseTable->rowCount();
        if(!this->_user.isAdmin() && image.getImageDescriptor().getAccessLevel() != "public")
            continue;
        ui->databaseTable->insertRow(i);
        ui->databaseTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(std::to_string(image.getImageDescriptor().getId()))));
        ui->databaseTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getTitle())));
        ui->databaseTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getSource())));
        ui->databaseTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getAuthor())));
        ui->databaseTable->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getAccessLevel())));
        ui->databaseTable->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(image.getImageDescriptor().getWeight()))));
    }
}

void ListWindow::selectDatabaseHandler() {
    QFileDialog databaseDialog;
    databaseDialog.setFileMode(QFileDialog::Directory);
    QString databasePath = databaseDialog.getExistingDirectory(this, tr("Choisir un dossier"), "/home/");
    if(databasePath.isEmpty())
        return;
    this->_database.load(databasePath.toStdString());
    this->loadTable();
}

void ListWindow::addImageHandler() {
    DatabaseWindow *databaseWindow = new DatabaseWindow(this->_database);
    this->connect(databaseWindow, SIGNAL(imageAdded()), SLOT(loadTable()));
    databaseWindow->show();
}

void ListWindow::imageProcessingHandler() {
    ImageProcessingWindow *imageProcessingWindow = new ImageProcessingWindow(this->_database.getImageById(this->_imageId));
    imageProcessingWindow->show();
}

void ListWindow::imageDisplayHandler(const int row) {
    this->_imageId = ui->databaseTable->item(row, 0)->text().toInt();
    ui->image->setPixmap(QPixmap(QString::fromStdString(this->_database.getImageById(this->_imageId).getImageDescriptor().getPath())).scaledToWidth(ui->imageGroup->width()));
}

void ListWindow::exitHandler() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Quitter");
    msgBox.setInformativeText("Êtes-vous sur de vouloir quitter ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes) {
        emit logout();
        this->close();
    }
}
