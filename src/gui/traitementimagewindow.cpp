#include "traitementimagewindow.h"
#include "ui_traitementimagewindow.h"
#include "secondwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

TraitementImageWindow::TraitementImageWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::TraitementImageWindow)
{
    ui->setupUi(this);
    connect(ui->actionfiltrage, &QAction::triggered, this, &TraitementImageWindow::informationfiltrage);
}

TraitementImageWindow::~TraitementImageWindow() {
    delete ui;
}

void TraitementImageWindow::on_EXITtraitement_clicked() {
    TraitementImageWindow::close();
    MainWindow *login = new MainWindow;
    login->show();
}

void TraitementImageWindow::on_returnButtonTraitement_clicked() {
    TraitementImageWindow::close() ;
    SecondWindow *fenetre = new SecondWindow;
    fenetre->show();
}

void TraitementImageWindow::informationfiltrage() {
    QMessageBox::information(this,"Bruit poivre et sel","Pour un bruit de type poivre et sel utiliser un filtre ....");
    QMessageBox::information(this,"Bruit Gaussien","Pour un bruit de type gaussien utiliser un filtre ....");

    /*QMessageBox msgBox;
     msgBox.setText("Bruit poivre et sel Pour un bruit de type poivre et sel utiliser un filtre ....");
     msgBox.exec(); */
}
