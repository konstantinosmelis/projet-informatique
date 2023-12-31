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
};

#endif //IMAGE_H
