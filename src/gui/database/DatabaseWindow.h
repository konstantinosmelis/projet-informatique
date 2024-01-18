#ifndef DATABASEWINDOWS_H
#define DATABASEWINDOWS_H

#include <QMainWindow>

namespace Ui {
    class DatabaseWindow;
}

class DatabaseWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit DatabaseWindow(QWidget *parent = nullptr);
        ~DatabaseWindow();

    private slots:
        void on_exitButton_clicked();
        void on_returnButton_clicked();

    private:
        Ui::DatabaseWindow *ui;
};

#endif // DATABASEWINDOWS_H
