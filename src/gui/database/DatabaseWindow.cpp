#include "DatabaseWindow.h"
#include "../../../ui/ui_databasewindow.h"

#include "../login/LoginWindow.h"
#include "../list/ListWindow.h"

DatabaseWindow::DatabaseWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::DatabaseWindow)
{
    ui->setupUi(this);
}

DatabaseWindow::~DatabaseWindow() {
    delete ui;
}

void DatabaseWindow::on_exitButton_clicked() {
    this->close();
    LoginWindow *login  = new LoginWindow;
    login->show();
}

void DatabaseWindow::on_returnButton_clicked() {
    this->close();
    ListWindow *fenetre = new ListWindow;
    fenetre->show();
}