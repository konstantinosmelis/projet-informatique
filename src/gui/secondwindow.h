#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QMainWindow>

namespace Ui {
    class SecondWindow;
}

class SecondWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit SecondWindow(QWidget *parent = nullptr);
        ~SecondWindow();

    private slots:
        void on_LoadImage_clicked();
        void on_ModifDatabaseButton_clicked();
        void on_TraitemenButton_clicked();
        void on_EXITBUTTON_clicked();

    private:
        Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
