/********************************************************************************
** Form generated from reading UI file 'databasewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASEWINDOW_H
#define UI_DATABASEWINDOW_H

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

class Ui_DatabaseWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *imageNameLabel;
    QLabel *imageCostLabel;
    QTextEdit *imageNameText;
    QLabel *imageSourceLabel;
    QLabel *accessLevelLabel;
    QTextEdit *imageCostText;
    QTextEdit *imageSourceText;
    QTextEdit *accessLevelText;
    QGroupBox *imageGroup;
    QPushButton *LoadImage;
    QTextEdit *textEdit;
    QPushButton *exitButton;
    QPushButton *returnButton;
    QPushButton *saveButton;
    QGroupBox *groupBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Ajout_dans_la_base_de_données)
    {
        if (Ajout_dans_la_base_de_données->objectName().isEmpty())
            Ajout_dans_la_base_de_données->setObjectName("Ajout_dans_la_base_de_donn\303\251es");
        Ajout_dans_la_base_de_données->resize(800, 600);
        centralwidget = new QWidget(Ajout_dans_la_base_de_données);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(360, 20, 401, 341));
        imageNameLabel = new QLabel(groupBox);
        imageNameLabel->setObjectName("imageNameLabel");
        imageNameLabel->setGeometry(QRect(10, 40, 111, 20));
        imageCostLabel = new QLabel(groupBox);
        imageCostLabel->setObjectName("imageCostLabel");
        imageCostLabel->setGeometry(QRect(10, 80, 101, 20));
        imageNameText = new QTextEdit(groupBox);
        imageNameText->setObjectName("imageNameText");
        imageNameText->setGeometry(QRect(150, 30, 201, 31));
        imageSourceLabel = new QLabel(groupBox);
        imageSourceLabel->setObjectName("imageSourceLabel");
        imageSourceLabel->setGeometry(QRect(30, 120, 63, 20));
        accessLevelLabel = new QLabel(groupBox);
        accessLevelLabel->setObjectName("accessLevelLabel");
        accessLevelLabel->setGeometry(QRect(20, 220, 111, 20));
        imageCostText = new QTextEdit(groupBox);
        imageCostText->setObjectName("imageCostText");
        imageCostText->setGeometry(QRect(150, 70, 201, 31));
        imageSourceText = new QTextEdit(groupBox);
        imageSourceText->setObjectName("imageSourceText");
        imageSourceText->setGeometry(QRect(150, 110, 201, 41));
        accessLevelText = new QTextEdit(groupBox);
        accessLevelText->setObjectName("accessLevelText");
        accessLevelText->setGeometry(QRect(150, 210, 201, 41));
        imageGroup = new QGroupBox(centralwidget);
        imageGroup->setObjectName("imageGroup");
        imageGroup->setGeometry(QRect(10, 10, 291, 111));
        LoadImage = new QPushButton(imageGroup);
        LoadImage->setObjectName("LoadImage");
        LoadImage->setGeometry(QRect(60, 60, 121, 29));
        textEdit = new QTextEdit(imageGroup);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(0, 20, 281, 31));
        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(70, 388, 93, 41));
        returnButton = new QPushButton(centralwidget);
        returnButton->setObjectName("returnButton");
        returnButton->setGeometry(QRect(170, 390, 93, 41));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(420, 390, 101, 41));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(30, 140, 291, 221));
        Ajout_dans_la_base_de_données->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Ajout_dans_la_base_de_données);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        Ajout_dans_la_base_de_données->setMenuBar(menubar);
        statusbar = new QStatusBar(Ajout_dans_la_base_de_données);
        statusbar->setObjectName("statusbar");
        Ajout_dans_la_base_de_données->setStatusBar(statusbar);

        retranslateUi(Ajout_dans_la_base_de_données);

        QMetaObject::connectSlotsByName(Ajout_dans_la_base_de_données);
    } // setupUi

    void retranslateUi(QMainWindow *Ajout_dans_la_base_de_données)
    {
        Ajout_dans_la_base_de_données->setWindowTitle(QCoreApplication::translate("DatabaseWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DatabaseWindow", "Informations de l'image", nullptr));
        imageNameLabel->setText(QCoreApplication::translate("DatabaseWindow", "Nom de l'image", nullptr));
        imageCostLabel->setText(QCoreApplication::translate("DatabaseWindow", "Co\303\273t de l'image ", nullptr));
        imageSourceLabel->setText(QCoreApplication::translate("DatabaseWindow", "Source", nullptr));
        accessLevelLabel->setText(QCoreApplication::translate("DatabaseWindow", "Niveau d'acc\303\250s", nullptr));
        imageGroup->setTitle(QCoreApplication::translate("DatabaseWindow", "Charger l'image", nullptr));
        LoadImage->setText(QCoreApplication::translate("DatabaseWindow", "Charger", nullptr));
        exitButton->setText(QCoreApplication::translate("DatabaseWindow", "Quitter", nullptr));
        returnButton->setText(QCoreApplication::translate("DatabaseWindow", "Retour", nullptr));
        saveButton->setText(QCoreApplication::translate("DatabaseWindow", "Enregistrer", nullptr));
        groupBox_2->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class DatabaseWindow: public Ui_DatabaseWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASEWINDOW_H
