#include "traitementimagewindow.h"
#include "ui_traitementimagewindow.h"
#include "list/ListWindow.h"
#include "login/LoginWindow.h"

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
    this->close();
    LoginWindow *login = new LoginWindow;
    login->show();
}

void TraitementImageWindow::on_returnButtonTraitement_clicked() {
    this->close() ;
    ListWindow *fenetre = new ListWindow;
    fenetre->show();
}

void TraitementImageWindow::informationfiltrage() {
    QMessageBox::information(this,"Bruit poivre et sel","Pour un bruit de type poivre et sel utiliser un filtre ....");
    QMessageBox::information(this,"Bruit Gaussien","Pour un bruit de type gaussien utiliser un filtre ....");

    /*QMessageBox msgBox;
     msgBox.setText("Bruit poivre et sel Pour un bruit de type poivre et sel utiliser un filtre ....");
     msgBox.exec(); */
}
