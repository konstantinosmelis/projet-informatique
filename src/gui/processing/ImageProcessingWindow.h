#ifndef TRAITEMENTIMAGEWINDOW_H
#define TRAITEMENTIMAGEWINDOW_H

#include <QMainWindow>

namespace Ui {
    class ImageProcessingWindow;
}

class ImageProcessingWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit ImageProcessingWindow(QWidget *parent = nullptr);
        ~ImageProcessingWindow();
        void informationfiltrage() ;

    private slots:
        void on_EXITtraitement_clicked();
        void on_returnButtonTraitement_clicked();

    private:
        Ui::ImageProcessingWindow *ui;
};

#endif // TRAITEMENTIMAGEWINDOW_H
