#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

#include "../user/User.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::MainWindow(const std::string &userPath, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->_userPath = userPath;
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_loginButton_clicked() {
    User user(ui->usernameText->toPlainText().toStdString(), ui->passwordText->toPlainText().toStdString());
    if(user.verifyLogin(this->_userPath) && !user.getUsername().empty()) {
        this->hide();
        SecondWindow *secondFenetre = new SecondWindow(user);
        secondFenetre->show();
    }
    else {
        ui->passwordText->clear();
    }
}
