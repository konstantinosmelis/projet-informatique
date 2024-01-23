#ifndef TRAITEMENTIMAGEWINDOW_H
#define TRAITEMENTIMAGEWINDOW_H

#include <QMainWindow>

#include "../../database/Database.h"

namespace Ui {
    class ImageProcessingWindow;
}

class ImageProcessingWindow : public QMainWindow {
    Q_OBJECT

    public:
        explicit ImageProcessingWindow(const Image &, QWidget *parent = nullptr);
        ~ImageProcessingWindow();

    private slots:
        void histogramHandler();
        void normalisationHandler();
        void equalizationHandler();
        void borderEnhancementHandler();
        void erosionHandler();
        void dilationhandler();
        void segmetationHandler();
        void lineDetectionhandler();
        void saltpepperNoiseHandler();
        void gaussianNoiseHandler();
        void returnHandler();
        void saveHandler();
        void displayImage();

    private:
        Ui::ImageProcessingWindow *ui;
        Image _image;
};

#endif // TRAITEMENTIMAGEWINDOW_H
