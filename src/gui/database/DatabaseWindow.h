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
        void on_loadImageButton_clicked();
        void on_finishButton_clicked();
        void on_returnButton_clicked();

    private:
        Ui::DatabaseWindow *ui;
        Database *_database;
        QString _imagePath;
};

#endif // DATABASEWINDOWS_H
