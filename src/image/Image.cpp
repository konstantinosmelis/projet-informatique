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
