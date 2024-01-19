#include "ListWindow.h"
#include "../../../ui/ui_listwindow.h"

#include "../database/DatabaseWindow.h"
#include "../processing/ImageProcessingWindow.h"
#include "../login/LoginWindow.h"

#include <QMessageBox>

ListWindow::ListWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ListWindow)
{
    ui->setupUi(this);
}

ListWindow::ListWindow(const User &user, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ListWindow)
{
    this->_user = user;
    ui->setupUi(this);
}

ListWindow::~ListWindow() {
    delete ui;
}

void ListWindow::on_addImageButton_clicked() {
    DatabaseWindow *DataBaseFenetre = new DatabaseWindow;
    DataBaseFenetre->show();
    this->hide();
}

void ListWindow::on_imageProcessingButton_clicked() {
    ImageProcessingWindow *TraitementFenetre = new ImageProcessingWindow;
    TraitementFenetre->show();
    this->hide();
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
