#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "secondwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow:: on_LoginButton_clicked(){
    MainWindow::hide();
    SecondWindow *secondFenetre = new SecondWindow;
    secondFenetre->show();
}
