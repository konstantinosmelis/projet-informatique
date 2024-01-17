#include "databasewindow.h"
#include "ui_databasewindow.h"
#include "mainwindow.h"
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
    MainWindow *login  = new MainWindow;
    login->show();
}

void databaseWindow::on_ReturnDB_clicked() {
    databaseWindow::close();
    SecondWindow *fenetre = new SecondWindow;
    fenetre->show();
}
