#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class LoginWindow;
}
QT_END_NAMESPACE

class LoginWindow : public QMainWindow {
    Q_OBJECT

    public:
        LoginWindow(QWidget *parent = nullptr);
        LoginWindow(const std::string &, QWidget *parent = nullptr);
        ~LoginWindow();

    private slots:
        void logout();
        void on_loginButton_clicked();

    private:
        Ui::LoginWindow *ui;
        std::string _userPath;
};

#endif // MAINWINDOW_H
