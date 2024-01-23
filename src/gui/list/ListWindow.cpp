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
    int i = 0;
    ui->databaseTable->setRowCount(0);
    ui->databaseTable->setRowCount((int) this->_database.getImages().size());
    for(const Image &image : this->_database.getImages()) {
        ui->databaseTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(std::to_string(image.getImageDescriptor().getId()))));
        ui->databaseTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getTitle())));
        ui->databaseTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getSource())));
        ui->databaseTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getAuthor())));
        ui->databaseTable->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getAccessLevel())));
        ui->databaseTable->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(std::to_string(image.getImageDescriptor().getWeight()))));
        i++;
    }
}

void ListWindow::selectDatabaseHandler() {
    QFileDialog databaseDialog;
    databaseDialog.setFileMode(QFileDialog::Directory);
    QString databasePath = databaseDialog.getExistingDirectory(this, tr("Choisir un dossier"), "/home/");
    this->_database.load(databasePath.toStdString());
    this->loadTable();
}

void ListWindow::addImageHandler() {
    DatabaseWindow *databaseWindow = new DatabaseWindow(this->_database);
    this->connect(databaseWindow, SIGNAL(imageAdded()), SLOT(loadTable()));
    databaseWindow->show();
}

void ListWindow::imageProcessingHandler() {
    ImageProcessingWindow *TraitementFenetre = new ImageProcessingWindow;
    TraitementFenetre->show();
}

void ListWindow::imageDisplayHandler(const int row) {
    ui->image->setPixmap(QPixmap(QString::fromStdString(this->_database.getImages().at(row).getImageDescriptor().getPath())).scaledToWidth(ui->imageGroup->width()));
}

void ListWindow::exitHandler() {
    QMessageBox msgBox;
    msgBox.setWindowTitle("Quitter");
    msgBox.setInformativeText("Etes-vous sur de vouloir quitter ?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes) {
        emit logout();
        this->close();
    }
}
