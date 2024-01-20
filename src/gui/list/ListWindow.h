#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

#include "../../database/Database.h"
#include "../../user/User.h"

namespace Ui {
    class ListWindow;
}

class ListWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit ListWindow(const User &, QWidget *parent = nullptr);
        ~ListWindow();

    private slots:
        void loadTable() const;
        void on_addImageButton_clicked();
        void on_imageProcessingButton_clicked();
        void on_exitButton_clicked();

    private:
        Ui::ListWindow *ui;
        User _user;
        Database _database;
};

#endif // SECONDWINDOW_H
