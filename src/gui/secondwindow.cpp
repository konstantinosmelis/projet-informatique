#include "secondwindow.h"
#include "ui_secondwindow.h"
#include "database/DatabaseWindow.h"
#include "traitementimagewindow.h"
#include "login/LoginWindow.h"
#include <QMessageBox>

SecondWindow::SecondWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::SecondWindow(const User &user, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    this->_user = user;
    ui->setupUi(this);
}

SecondWindow::~SecondWindow() {
    delete ui;
}

void SecondWindow::on_LoadImage_clicked() {

}

void SecondWindow::on_ModifDatabaseButton_clicked() {
    DatabaseWindow *DataBaseFenetre = new DatabaseWindow;
    DataBaseFenetre->show();
    SecondWindow::hide();
}

void SecondWindow::on_TraitemenButton_clicked() {
    TraitementImageWindow *TraitementFenetre = new TraitementImageWindow;
    TraitementFenetre->show();
    SecondWindow::hide();
}

void SecondWindow::on_EXITBUTTON_clicked() {
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

    SecondWindow::close();
    LoginWindow *login = new LoginWindow;
    login->show();
}
