#include "Projetinformatique.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Projetinformatique w;
    w.show();
    return a.exec();
}
