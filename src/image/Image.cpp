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
void Image::convolution(const cv::Mat &kernel, const int mode) {
    int i, j, k, l, x, y;
    cv::Mat temp;
    cv::Vec3f sum;
    if(mode == 1) { // use the opencv filter2D function
        cv::filter2D(this->_image, this->_image, -1, kernel);
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
                        sum += kernel.at<int>(k, l) * temp.at<cv::Vec3b>((x < 0 ? 0 : (x > temp.rows ? temp.rows : x)), (y < 0 ? 0 : (y > temp.cols ? temp.cols : y))); // For borders we use the mirror metod
                    }
                }
                this->_image.at<cv::Vec3b>(i, j) = sum / cv::sum(kernel)[0]; // update the image with our new image
            }
        }
    }
}
