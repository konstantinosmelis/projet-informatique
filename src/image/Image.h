#ifndef IMAGE_H
#define IMAGE_H

#include <opencv2/opencv.hpp>
#include "../descriptor/ImageDescriptor.h"

class Image {
    private:
        cv::Mat _image; /** A matrix storing the image */
        ImageDescriptor _descriptor; /** The descriptor of the image */

    public:
        /**
         * \brief Creates an Image which stores
         * this matrix and the descriptor
         */
        Image(const ImageDescriptor &descriptor);

        /**
         * \brief Get the matrix storing the image
         */
        cv::Mat getImage() const;

        /**
         * @brief Get the image's descriptor
         */
        ImageDescriptor getImageDescriptor() const;

        /**
         * \brief Set the matrix of the image
         */
        void setImage(const cv::Mat &);

        /**
         * \brief Set the descriptor for this image
         */
        void setImageDescriptor(const ImageDescriptor &);

        /**
         * \brief Create the matrix storing the image
         */
        void loadImage();

        /**
         * \brief Save the image into a file
         */
        void save(const std::string &) const;

        /**
         * \brief Show the image using cv::imshow
         */
        void show() const;

        /**
         * \brief Create the histogram of each color channel
         */
        std::vector<std::vector<int>> histogram();

        /**
         * \brief Apply by convolution a kernel to the image
         */
        void convolution(cv::Mat &, const int);

        /**
         * \brief Calculate the gradient of the grayscale image
         */
        cv::Mat gradient();

        /**
         * \brief Enhance the borders of the objects in the grayscale image
         */
        void borderEnhancement();

        /**
         * \brief Apply median filter to image
         */
        void applyMedianFilter(const int);

        /**
         * \brief Erode the image
         */
        void applyErosionFilter(const int, const int);

        /**
         * \brief Dilate the image
         */
        void applyDilationFilter(const int, const int);

        /**
         * \brief Segment the image by chosing upper and lower bound parameters
         */
        void colorSegmentation(const cv::Scalar& lowerBound, const cv::Scalar& upperBound);

        /**
         * \brief Add salt pepper noise to the image
         */
        void saltpepperNoise();

        /**
         * \brief Add gaussian noise to the image
         */
        void gaussianNoise(double);
}; 

#endif //IMAGE_H
