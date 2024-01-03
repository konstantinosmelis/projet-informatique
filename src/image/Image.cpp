#include "Image.h"

/**
 * \param descriptor a descriptor to give to the image
 */
Image::Image(const ImageDescriptor &descriptor) {
    this->_descriptor = descriptor;
    this->loadImage();
}

/**
 * \return the matrix storing the image
 */
cv::Mat Image::getImage() const {
    return this->_image;
}

/**
 * \return the image descriptior
 */
ImageDescriptor Image::getImageDescriptor() const {
    return this->_descriptor;
}

/**
 * \param image a matrix storing an image
 */
void Image::setImage(const cv::Mat &image) {
    this->_image = image;
}

/**
 * \param descriptor a descriptor for the image
 * \note This will reload the image due to the fact
 * that the descriptor stores the path to the image
 */
void Image::setImageDescriptor(const ImageDescriptor &descriptor) {
    this->_descriptor = descriptor;
    this->loadImage(); // update the image in case the image is different
}

void Image::loadImage() {
    this->_image = cv::imread(this->_descriptor.getPath()); // load the image using opencv
}

/**
 * \param path the path to save the image
 */
void Image::save(const std::string &path) const {
    cv::imwrite(path, this->_image); // save the image to a specific path without saving it to the database
}

void Image::show() const {
    cv::imshow(this->_descriptor.getTitle(), this->_image); // display the image using opencv
    cv::waitKey();
}

/**
 * \return a vector for a grayscale image
 * \note The vector contains every histogram
 * for each color chanel
 */
std::vector<std::vector<int>> Image::histogram() {
    int c, i, j;
    std::vector<std::vector<int>> hist = std::vector(3, std::vector(256, 0));
    cv::Vec3b pixel;
    for(i = 0; i < this->_image.rows; i++) { // for each line of the image
        for(j = 0; j < this->_image.cols; j++) { // for each column of the image
            pixel = this->_image.at<cv::Vec3b>(i, j); // the current pixel (i,j)
            for(c = 0; c < 3; c++) { // for each channel RGB
                hist.at(c)[(int) pixel[c]]++; // increment the value of the color level
            }
        }
    }
    return hist;
}


/**
 * \param kernelSize the size of the matrix that will be applied to the image as kernel
 * \params inputImage and outputImage a matrix of pixel's values
 */
void Image::applyMedianFilter(const cv::Mat& inputImage, cv::Mat& outputImage, int kernelSize) {
    /*
        cv::medianBlur(inputImage, outputImage, kernelSize);
    */
    if (inputImage.channels() == 1) {
        // Image en niveaux de gris
        outputImage = inputImage.clone();

        const int padding = kernelSize / 2;
        const int windowSize = kernelSize * kernelSize;

        std::vector<unsigned char> windowValues(windowSize);

        for (int i = 0; i < inputImage.rows; ++i) {
            for (int j = 0; j < inputImage.cols; ++j) {
                // Remplir le vecteur des valeurs de la fen�tre du noyau
                int index = 0;
                for (int k = -padding; k <= padding; ++k) {
                    for (int l = -padding; l <= padding; ++l) {
                        int ni = std::max(0, std::min(inputImage.rows - 1, i + k));
                        int nj = std::max(0, std::min(inputImage.cols - 1, j + l));
                        windowValues[index++] = inputImage.at<unsigned char>(ni, nj);
                    }
                }
                // Trouver la mediane sans tri en utilisant nth_element
                std::nth_element(windowValues.begin(), windowValues.begin() + windowSize / 2, windowValues.end());
                // Assigner la mediane au pixel central
                outputImage.at<unsigned char>(i, j) = windowValues[windowSize / 2];
            }
        }
    }
    else if (inputImage.channels() == 3) {
        // Image en couleur
        std::vector<cv::Mat> channels;
        cv::split(inputImage, channels);

        for (int c = 0; c < 3; ++c) {
            applyMedianFilter(channels[c], channels[c], kernelSize);
        }

        cv::merge(channels, outputImage);
    }
}


void Image::applyErosionFilter(const cv::Mat& inputImage, cv::Mat& outputImage, int iterations  = 1  , int kernelSize = 3 ) {
    if (inputImage.channels() == 1) {
        // Image en niveaux de gris
        outputImage = inputImage.clone();

        const int padding = kernelSize / 2;
        const int windowSize = kernelSize * kernelSize;

        for (int iter = 0; iter < iterations; ++iter) {
            cv::Mat tempImage = outputImage.clone();

            for (int i = 0; i < inputImage.rows; ++i) {
                for (int j = 0; j < inputImage.cols; ++j) {
                    // Creer une fenetre du noyau
                    std::vector<unsigned char> windowValues(windowSize);

                    int index = 0;
                    for (int k = -padding; k <= padding; ++k) {
                        for (int l = -padding; l <= padding; ++l) {
                            int ni = std::max(0, std::min(inputImage.rows - 1, i + k));
                            int nj = std::max(0, std::min(inputImage.cols - 1, j + l));
                            windowValues[index++] = tempImage.at<unsigned char>(ni, nj);
                        }
                    }

                    // Appliquer l'�rosion en prenant le min du noyau
                    outputImage.at<unsigned char>(i, j) = *std::min_element(windowValues.begin(), windowValues.end());
                }
            }
        }
    }
    else if (inputImage.channels() == 3) {
        // Image en couleur
        std::vector<cv::Mat> channels;
        cv::split(inputImage, channels);

        for (int c = 0; c < 3; ++c) {
            applyErosionFilter(channels[c], channels[c], iterations, kernelSize);
        }

        cv::merge(channels, outputImage);
    }
}

void Image::applyDilationFilter(const cv::Mat& inputImage, cv::Mat& outputImage, int iterations = 1, int kernelSize = 3) {
    if (inputImage.channels() == 1) {
        // Image en niveaux de gris
        outputImage = inputImage.clone();

        const int padding = kernelSize / 2;
        const int windowSize = kernelSize * kernelSize;

        for (int iter = 0; iter < iterations; ++iter) {
            cv::Mat tempImage = outputImage.clone();

            for (int i = 0; i < inputImage.rows; ++i) {
                for (int j = 0; j < inputImage.cols; ++j) {
                    // Creer une fenetre du noyau
                    std::vector<unsigned char> windowValues(windowSize);

                    int index = 0;
                    for (int k = -padding; k <= padding; ++k) {
                        for (int l = -padding; l <= padding; ++l) {
                            int ni = std::max(0, std::min(inputImage.rows - 1, i + k));
                            int nj = std::max(0, std::min(inputImage.cols - 1, j + l));
                            windowValues[index++] = tempImage.at<unsigned char>(ni, nj);
                        }
                    }

                    // Appliquer la dilatation en prenant le max du noyau
                    outputImage.at<unsigned char>(i, j) = *std::max_element(windowValues.begin(), windowValues.end());
                }
            }
        }
    }
    else if (inputImage.channels() == 3) {
        // Image en couleur
        std::vector<cv::Mat> channels;
        cv::split(inputImage, channels);

        for (int c = 0; c < 3; ++c) {
            applyDilationFilter(channels[c], channels[c], iterations, kernelSize);
        }

        cv::merge(channels, outputImage);
    }
}
