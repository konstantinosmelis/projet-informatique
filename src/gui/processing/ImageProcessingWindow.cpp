#include "ImageProcessingWindow.h"

#include "../../../ui/ui_imageprocessingwindow.h"

#include <QPushButton>
#include <QFileDialog>

ImageProcessingWindow::ImageProcessingWindow(const Image image, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::ImageProcessingWindow)
{
    this->_image = image;
    ui->setupUi(this);
    ui->imageBeforeProcessing->setPixmap(QPixmap(QString::fromStdString(this->_image.getImageDescriptor().getPath())).scaledToWidth(ui->imageBeforeProcessing->width()));

    this->connect(ui->histogramButton, &QPushButton::clicked, this, [=]() { this->histogramHandler(); });
    this->connect(ui->normalisationButton, &QPushButton::clicked, this, [=]() { this->normalisationHandler(); });
    this->connect(ui->equalizationButton, &QPushButton::clicked, this, [=]() { this->equalizationHandler(); });
    this->connect(ui->erosionButton, &QPushButton::clicked, this, [=]() { this->erosionHandler(); });
    this->connect(ui->dilationButton, &QPushButton::clicked, this, [=]() { this->dilationhandler(); });
    this->connect(ui->borderEnhancementButton, &QPushButton::clicked, this, [=]() { this->borderEnhancementHandler(); });
    this->connect(ui->segmentationButton, &QPushButton::clicked, this, [=]() { this->segmetationHandler(); });
    this->connect(ui->lineDetectionButton, &QPushButton::clicked, this, [=]() { this->lineDetectionhandler(); });
    this->connect(ui->saltpepperNoiseButton, &QPushButton::clicked, this, [=]() { this->saltpepperNoiseHandler(); });
    this->connect(ui->gaussianNoiseButton, &QPushButton::clicked, this, [=]() { this->gaussianNoiseHandler(); });
    this->connect(ui->saveButton, &QPushButton::clicked, this, [=]() { this->saveHandler(); });
    this->connect(ui->returnButton, &QPushButton::clicked, this, [=]() { this->returnHandler(); });
}

ImageProcessingWindow::~ImageProcessingWindow() {
    delete ui;
}

void ImageProcessingWindow::histogramHandler() {
    std::vector<std::vector<int>> histogram = this->_image.histogram();
}

void ImageProcessingWindow::normalisationHandler() {
    this->_image.normalizeHistogram();
    this->displayImage();
}

void ImageProcessingWindow::equalizationHandler() {
    this->_image.equalizeHistogram(ui->equalizationMinValue->value(), ui->equalizationMaxValue->value());
    this->displayImage();
}

void ImageProcessingWindow::erosionHandler() {
    this->_image.applyErosionFilter(1, 3);
    this->displayImage();
}

void ImageProcessingWindow::dilationhandler() {
    this->_image.applyDilationFilter(1, 3);
    this->displayImage();
}

void ImageProcessingWindow::borderEnhancementHandler() {
    this->_image.borderEnhancement();
    this->_image.setColorModel(cv::COLOR_GRAY2BGR);
    this->displayImage();
}

void ImageProcessingWindow::segmetationHandler() {
    this->_image.colorSegmentation(ui->redMinValue->value(), ui->redMaxValue->value(), ui->greenMinValue->value(), ui->greenMaxValue->value(), ui->blueMinValue->value(), ui->blueMaxValue->value());
    this->displayImage();
}

void ImageProcessingWindow::lineDetectionhandler() {
    this->_image.detectLines(ui->lineDetectionThreshold->value(), ui->lineDetectionMinLength->value(), ui->lineDetectionMaxGapValue->value());
    this->displayImage();
}

void ImageProcessingWindow::saltpepperNoiseHandler() {
    this->_image.saltpepperNoise(ui->saltpeperPercentageValue->value());
    this->displayImage();
}

void ImageProcessingWindow::gaussianNoiseHandler() {
    this->_image.gaussianNoise(ui->gaussianNoiseVarianceValue->value());
    this->displayImage();
}

void ImageProcessingWindow::returnHandler() {
    this->_image = Image();
    this->destroy(this);
}

void ImageProcessingWindow::saveHandler() {
    QString imagePath = QFileDialog::getSaveFileName(this, tr("Choisir une image"), "/home/untitled.png", tr("Image Files (*.png *.jpg)"));
    if(imagePath.isEmpty())
        return;
    this->_image.save(imagePath.toStdString());
}

void ImageProcessingWindow::displayImage() {
    // Display the modified image in the QLabel (assuming ui->imageLabelAfterProcessing is a QLabel)
    QImage qimg((uchar*) this->_image.getImage().data, this->_image.getImage().cols, this->_image.getImage().rows, QImage::Format_BGR888);
    ui->imageAfterProcessing->setPixmap(QPixmap::fromImage(qimg).scaledToWidth(ui->imageAfterProcessing->width()));
}
