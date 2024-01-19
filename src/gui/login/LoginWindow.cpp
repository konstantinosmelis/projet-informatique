#include "LoginWindow.h"
#include "../../../ui/ui_loginwindow.h"

#include "../list/ListWindow.h"

#include "../../user/User.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::LoginWindow(const std::string &userPath, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    this->_userPath = userPath;
    ui->setupUi(this);
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::on_loginButton_clicked() {
    User user(ui->usernameText->toPlainText().toStdString(), ui->passwordText->toPlainText().toStdString());
    if(user.verifyLogin(this->_userPath) && !user.getUsername().empty()) {
        this->hide();
        ListWindow *secondFenetre = new ListWindow(user);
        secondFenetre->show();
    }
    else {
        ui->passwordText->clear();
    }
}
