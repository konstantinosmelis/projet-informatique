#include <iostream>
#include <QApplication>
#include "gui/login/LoginWindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    // a.setWindowIcon(QIcon("/home/dinos/Development/C-C++/image-processor/resources/image_processor.png"));
    LoginWindow w(argv[1]);
    w.show();
    std::cout << "Hello world!" << std::endl;
    return QApplication::exec();
}
