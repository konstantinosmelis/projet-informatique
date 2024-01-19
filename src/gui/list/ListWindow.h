#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

#include "../../user/User.h"

namespace Ui {
    class ListWindow;
}

class ListWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit ListWindow(QWidget *parent = nullptr);
        ListWindow(const User &, QWidget *parent = nullptr);
        ~ListWindow();

    private slots:
        void on_addImageButton_clicked();
        void on_imageProcessingButton_clicked();
        void on_exitButton_clicked();

    private:
        Ui::ListWindow *ui;
        User _user;
};

#endif // SECONDWINDOW_H
