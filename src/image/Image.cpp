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
 * \param kernel a matrix that will be applied to the image
 * \param mode an integer (1: use opencv's filter2D function)
 */
void Image::convolution(cv::Mat &kernel, const int mode) {
    int i, j, k, l, x, y, kerSum;
    cv::Mat temp;
    cv::Vec3f sum;
    kerSum = cv::sum(kernel)[0];
    if(mode == 1) { // use the opencv filter2D function
        kernel.convertTo(kernel, CV_16F);
        cv::filter2D(this->_image, this->_image, -1, kernel / (kerSum > 0 ? kerSum : 1));
    }
    else {
        temp = this->_image;
        for(i = 0; i < temp.rows; i++) { // for each line of the image
            for(j = 0; j < temp.cols; j++) { // for each column of the image
                sum = cv::Vec3f::all(0); // we initialize the value to 0
                for(k = 0; k < kernel.rows; k++) { // for each line of the kernel
                    for(l = 0; l < kernel.cols; l++) { // for each column of the kernel
                        // the coordinates of the image to consider
                        x = i + k - std::floor(kernel.rows / 2);
                        y = j + l - std::floor(kernel.cols / 2);
                        // update the new value of the (i, j) pixel
                        sum += kernel.at<uint8_t>(k, l) * temp.at<cv::Vec3b>((x < 0 ? 0 : (x > temp.rows ? temp.rows : x)), (y < 0 ? 0 : (y > temp.cols ? temp.cols : y))); // For borders we use the mirror metod
                    }
                }
                this->_image.at<cv::Vec3b>(i, j) = sum / (kerSum > 0 ? kerSum : 1); // update the image with our new image
            }
        }
    }
}

/**
 * \return the gradient image
 */
cv::Mat Image::gradient() {
    cv::Mat grayscale, gradx, grady, grad;
    // Convert BGR image to grayscale image
    cv::cvtColor(this->_image, grayscale, cv::COLOR_BGR2GRAY);
    // Apply Sobel filter
    cv::Sobel(grayscale, gradx, CV_32F, 1, 0);
    cv::Sobel(grayscale, grady, CV_32F, 0, 1);
    // Calculate gradient norm
    cv::magnitude(gradx, grady, grad);
    grad.convertTo(grad, CV_8U);
    return grad;
}

/**
 * \note The image is calculated by the following formula:
 * enhanced = grayscale + (0.8 * gradient)
 */
void Image::borderEnhancement() {
    cv::Mat grayscale, gradient;
    // Convert image to grayscale
    cv::cvtColor(this->_image, grayscale, cv::COLOR_BGR2GRAY);
    // Calculate gradient
    gradient = this->gradient();
    // Enhance borders in the image
    this->_image = grayscale + (.8 * gradient);
}

/**
 * \param kernelSize the size of the matrix that will be applied to the image as kernel
 */
void Image::applyMedianFilter(const int kernelSize = 3) {
    std::vector<cv::Mat> channels;
    cv::split(this->_image, channels);
    for(int c = 0; c < this->_image.channels(); c++) {
        cv::Mat tempImage = channels[c].clone();

        const int padding = kernelSize / 2;
        const int windowSize = kernelSize * kernelSize;
        std::vector<unsigned char> windowValues(windowSize);

        for (int i = 0; i < tempImage.rows; ++i) {
            for (int j = 0; j < tempImage.cols; ++j) {
                // Remplir le vecteur des valeurs de la fenetre du noyau
                int index = 0;
                for (int k = -padding; k <= padding; ++k) {
                    for (int l = -padding; l <= padding; ++l) {
                        int ni = std::max(0, std::min(tempImage.rows - 1, i + k));
                        int nj = std::max(0, std::min(tempImage.cols - 1, j + l));
                        windowValues[index++] = tempImage.at<unsigned char>(ni, nj);
                    }
                }
                // Trouver la mediane sans tri en utilisant nth_element
                std::nth_element(windowValues.begin(), windowValues.begin() + windowSize / 2, windowValues.end());
                // Assigner la mediane au pixel central
                channels[c].at<unsigned char>(i, j) = windowValues[windowSize / 2];
            }
        }
    }
    cv::merge(channels, this->_image);
}

/**
 * \param iterations maximum number of iterations
 * \param kernelSize the size of the matrix that will be applied to the image as kernel
 */
void Image::applyErosionFilter(const int iterations = 1, const int kernelSize = 3) {
    std::vector<cv::Mat> channels;
    cv::split(this->_image, channels);

    const int padding = kernelSize / 2;
    const int windowSize = kernelSize * kernelSize;

    for(int iter = 0; iter < iterations; ++iter) {
        for(int c = 0; c < this->_image.channels(); c++) {
            cv::Mat tempImage = channels[c].clone();
            for(int i = 0; i < tempImage.rows; ++i) {
                for(int j = 0; j < tempImage.cols; ++j) {
                    // Creer une fenetre du noyau
                    std::vector<unsigned char> windowValues(windowSize);
                    int index = 0;
                    for(int k = -padding; k <= padding; ++k) {
                        for(int l = -padding; l <= padding; ++l) {
                            int ni = std::max(0, std::min(tempImage.rows - 1, i + k));
                            int nj = std::max(0, std::min(tempImage.cols - 1, j + l));
                            windowValues[index++] = tempImage.at<unsigned char>(ni, nj);
                        }
                    }
                    // Appliquer l'erosion en prenant le min du noyau
                    channels[c].at<unsigned char>(i, j) = *std::min_element(windowValues.begin(), windowValues.end());
                }
            }
        }
    }
    cv::merge(channels, this->_image);
}

/**
 * \param iterations maximum number of iterations
 * \param kernelSize the size of the matrix that will be applied to the image as kernel
 */
void Image::applyDilationFilter(const int iterations = 1, const int kernelSize = 3) {
    std::vector<cv::Mat> channels;
    cv::split(this->_image, channels);

    const int padding = kernelSize / 2;
    const int windowSize = kernelSize * kernelSize;

    for(int iter = 0; iter < iterations; ++iter) {
        for(int c = 0; c < this->_image.channels(); c++) {
            cv::Mat tempImage = channels[c].clone();
            for(int i = 0; i < tempImage.rows; ++i) {
                for(int j = 0; j < tempImage.cols; ++j) {
                    // Creer une fenetre du noyau
                    std::vector<unsigned char> windowValues(windowSize);
                    int index = 0;
                    for(int k = -padding; k <= padding; ++k) {
                        for(int l = -padding; l <= padding; ++l) {
                            int ni = std::max(0, std::min(tempImage.rows - 1, i + k));
                            int nj = std::max(0, std::min(tempImage.cols - 1, j + l));
                            windowValues[index++] = tempImage.at<unsigned char>(ni, nj);
                        }
                    }
                    // Appliquer l'erosion en prenant le min du noyau
                    channels[c].at<unsigned char>(i, j) = *std::max_element(windowValues.begin(), windowValues.end());
                }
            }
        }
    }
    cv::merge(channels, this->_image);
}

void Image::colorSegmentation(const cv::Scalar &lowerBound, const cv::Scalar &upperBound) {
    // ça convertir l'image en espace de niveau de gris
    cv::Mat grayscale, outputImage;
    cv::cvtColor(this->_image, grayscale, cv::COLOR_BGR2GRAY);

    // appliquer le seuillage pour obtenir le masque
    cv::Mat mask;
    cv::inRange(grayscale, lowerBound, upperBound, mask);
    cv::bitwise_not(mask, mask);

    // appliquer le masque à l'image d'origine
    cv::bitwise_and(this->_image, this->_image, outputImage, mask);
    this->_image = outputImage;

    
void ajouterBruitPSNDG(Mat& image) {
    // Obtenir le nombre de lignes et de colonnes de l'image
    int rows = image.rows;
    int cols = image.cols;

    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Générer une valeur aléatoire entre 0 et 20
            int random_value = rand() % 21;

            // Appliquer le bruit poivre et sel
            if (random_value == 0) {
                // Poivre (noir)
                image.at<Vec3b>(i, j) = Vec3b(0, 0, 0);
            }
            else if (random_value == 20) {
                // Sel (blanc)
                image.at<Vec3b>(i, j) = Vec3b(255, 255, 255);
            }
            // Sinon, conservez la valeur du pixel d'origine
        }
    }
}
}
