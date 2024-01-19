#include "ListWindow.h"
#include "../../../ui/ui_listwindow.h"

#include "../database/DatabaseWindow.h"
#include "../processing/ImageProcessingWindow.h"
#include "../login/LoginWindow.h"

#include <QMessageBox>

ListWindow::ListWindow(const User &user, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ListWindow),
    _database()
{
    this->_user = user;
    ui->setupUi(this);
    this->_database.load("/home/dinos/Development/C-C++/image-processor/img/");
    this->loadTable();
}

ListWindow::~ListWindow() {
    delete ui;
}

void ListWindow::loadTable() const {
    int i = 0;
    ui->databaseTable->setRowCount((int) this->_database.getImages().size());
    for(const Image &image : this->_database.getImages()) {
        ui->databaseTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getTitle())));
        ui->databaseTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getSource())));
        ui->databaseTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getAuthor())));
        ui->databaseTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(std::to_string(image.getImageDescriptor().getWeight()))));
        ui->databaseTable->setItem(i, 4, new QTableWidgetItem(QString::fromStdString(image.getImageDescriptor().getAccessLevel())));
        i++;
    }
}

void ListWindow::on_addImageButton_clicked() {
    DatabaseWindow *databaseWindow = new DatabaseWindow(this->_database);
    databaseWindow->show();
}

void ListWindow::on_imageProcessingButton_clicked() {
    ImageProcessingWindow *TraitementFenetre = new ImageProcessingWindow;
    TraitementFenetre->show();
}

void ListWindow::on_exitButton_clicked() {
    // QMessageBox::warnin
    // StandarButton defaultButton = NoButton ;
    // QMessageBox::warning(this,"Attention","Voulez vous vraiment fermer",StandarButtons buttons = annuler);
    // QMessageBox msgBox;
    // msgBox.setText("The document has been modified.");
    // msgBox.exec();

    QMessageBox msgBox;
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    this->close();
    LoginWindow *login = new LoginWindow;
    login->show();
}
