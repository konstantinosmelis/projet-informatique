#ifndef DATABASEWINDOWS_H
#define DATABASEWINDOWS_H

#include <QMainWindow>

#include "../../database/Database.h"

namespace Ui {
    class DatabaseWindow;
}

class DatabaseWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit DatabaseWindow(Database &, QWidget *parent = nullptr);
        ~DatabaseWindow();

    signals:
        void imageAdded();

    private slots:
        void imageLoadingHandler();
        void imageAddedHandler();
        void returnHandler();

    private:
        Ui::DatabaseWindow *ui;
        Database *_database;
        QString _imagePath;
};

#endif // DATABASEWINDOWS_H
