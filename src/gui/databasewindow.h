#ifndef DATABASEWINDOWS_H
#define DATABASEWINDOWS_H

#include <QMainWindow>

namespace Ui {
    class databaseWindow;
}

class databaseWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit databaseWindow(QWidget *parent = nullptr);
        ~databaseWindow();

    private slots:
        void on_EXITDB_clicked();
        void on_ReturnDB_clicked();

    private:
        Ui::databaseWindow *ui;
};

#endif // DATABASEWINDOWS_H
