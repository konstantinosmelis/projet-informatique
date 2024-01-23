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

    signals:
        void logout();

    private slots:
        void loadTable() const;
        void selectDatabaseHandler();
        void addImageHandler();
        void imageProcessingHandler();
        void imageDisplayHandler(const int);
        void exitHandler();

    private:
        Ui::ListWindow *ui;
        User _user;
        Database _database;
        int _imageId;
};

#endif // SECONDWINDOW_H
