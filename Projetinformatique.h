#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Projetinformatique.h"

#include "./database/Database.h"


class Projetinformatique : public QMainWindow
{
    Q_OBJECT

public:
    Projetinformatique(QWidget *parent = nullptr);
    ~Projetinformatique();
private slots:
    //void testGetImages(Database);
    void on_pushButton_clicked();

private:
    Ui::ProjetinformatiqueClass ui;
    Database database;  // Ajoutez une instance de la classe Database à votre application

};
