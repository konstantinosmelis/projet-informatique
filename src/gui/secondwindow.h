#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

#include "../user/User.h"

namespace Ui {
    class SecondWindow;
}

class SecondWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit SecondWindow(QWidget *parent = nullptr);
        SecondWindow(const User &, QWidget *parent = nullptr);
        ~SecondWindow();

    private slots:
        void on_LoadImage_clicked();
        void on_ModifDatabaseButton_clicked();
        void on_TraitemenButton_clicked();
        void on_EXITBUTTON_clicked();

    private:
        Ui::SecondWindow *ui;
        User _user;
};

#endif // SECONDWINDOW_H
