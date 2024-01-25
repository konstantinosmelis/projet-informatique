#include "LoginWindow.h"
#include "../../../ui/ui_loginwindow.h"

#include "../list/ListWindow.h"

#include "../../user/User.h"

LoginWindow::LoginWindow(const std::string &userPath, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    this->_userPath = userPath;
    ui->setupUi(this);
    this->connect(ui->loginButton, &QPushButton::clicked,this, [=]() { this->loginHandler(); });
}

LoginWindow::~LoginWindow() {
    delete ui;
}

void LoginWindow::logout() {
    this->show();
}

void LoginWindow::loginHandler() {
    User user(ui->usernameText->text().toStdString(), ui->passwordText->text().toStdString());
    if(user.verifyLogin(this->_userPath) && !user.getUsername().empty()) {
        this->hide();
        ListWindow *listWindow = new ListWindow(user);
        listWindow->setAttribute(Qt::WA_DeleteOnClose);
        this->connect(listWindow, SIGNAL(logout()), SLOT(logout()));
        listWindow->show();
        ui->usernameText->clear();
        ui->passwordText->clear();
        ui->failedToConnectText->setText("");
    }
    else {
        ui->passwordText->clear();
        ui->failedToConnectText->setText("* nom d'utilisateur ou mot de passe incorrect.");
    }
}
