#include <iostream>
#include <QApplication>
#include <QPushButton>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    std::cout << "Hello world!" << std::endl;
    return QApplication::exec();
}
