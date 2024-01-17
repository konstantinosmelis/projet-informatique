#ifndef TRAITEMENTIMAGEWINDOW_H
#define TRAITEMENTIMAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
    class TraitementImageWindow;
}

class TraitementImageWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit TraitementImageWindow(QWidget *parent = nullptr);
        ~TraitementImageWindow();
        void informationfiltrage() ;

    private slots:
        void on_EXITtraitement_clicked();
        void on_returnButtonTraitement_clicked();

    private:
        Ui::TraitementImageWindow *ui;
};

#endif // TRAITEMENTIMAGEWINDOW_H
