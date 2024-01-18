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

    private:
        Ui::LoginWindow *ui;
        std::string _userPath;

    private slots:
        void on_loginButton_clicked();
};
#endif // MAINWINDOW_H
