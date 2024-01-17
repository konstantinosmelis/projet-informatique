#include <iostream>
#include <QApplication>
#include "gui/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout << "Hello world!" << std::endl;
    return QApplication::exec();
}
