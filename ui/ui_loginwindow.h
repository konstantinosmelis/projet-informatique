/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QTextEdit *usernameText;
    QTextEdit *passwordText;
    QPushButton *loginButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 255, 255);"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(200, 80, 280, 321));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        usernameText = new QTextEdit(groupBox);
        usernameText->setObjectName("usernameText");
        usernameText->setGeometry(QRect(12, 39, 256, 51));
        usernameText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        passwordText = new QTextEdit(groupBox);
        passwordText->setObjectName("passwordText");
        passwordText->setGeometry(QRect(10, 150, 256, 41));
        passwordText->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(80, 250, 93, 29));
        loginButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 110, 111, 20));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Segoe UI\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(12, 12, 91, 20));
        label_2->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 11pt \"Segoe UI\";"));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        groupBox->setTitle(QString());
        loginButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Mot de passe:", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "Identifiant:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
