#include "databasewindow.h"
#include "ui_databasewindow.h"
#include "login/LoginWindow.h"
#include "secondwindow.h"

databaseWindow::databaseWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::databaseWindow)
{
    ui->setupUi(this);
}

databaseWindow::~databaseWindow() {
    delete ui;
}

void databaseWindow::on_EXITDB_clicked() {
    databaseWindow::close();
    LoginWindow *login  = new LoginWindow;
    login->show();
}

void databaseWindow::on_ReturnDB_clicked() {
    databaseWindow::close();
    SecondWindow *fenetre = new SecondWindow;
    fenetre->show();
}
