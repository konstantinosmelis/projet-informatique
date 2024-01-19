#include "ImageProcessingWindow.h"
#include "../../../ui/ui_imageprocessingwindow.h"

#include "../list/ListWindow.h"
#include "../login/LoginWindow.h"

#include <QMessageBox>

ImageProcessingWindow::ImageProcessingWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ImageProcessingWindow)
{
    ui->setupUi(this);
    connect(ui->actionfiltrage, &QAction::triggered, this, &ImageProcessingWindow::informationfiltrage);
}

ImageProcessingWindow::~ImageProcessingWindow() {
    delete ui;
}

void ImageProcessingWindow::on_EXITtraitement_clicked() {
    this->close();
    LoginWindow *login = new LoginWindow;
    login->show();
}

void ImageProcessingWindow::on_returnButtonTraitement_clicked() {
    this->close() ;
    ListWindow *fenetre = new ListWindow;
    fenetre->show();
}

void ImageProcessingWindow::informationfiltrage() {
    QMessageBox::information(this,"Bruit poivre et sel","Pour un bruit de type poivre et sel utiliser un filtre ....");
    QMessageBox::information(this,"Bruit Gaussien","Pour un bruit de type gaussien utiliser un filtre ....");

    /*QMessageBox msgBox;
     msgBox.setText("Bruit poivre et sel Pour un bruit de type poivre et sel utiliser un filtre ....");
     msgBox.exec(); */
}
