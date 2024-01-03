#include "Database.h"

/**
 * \return a vector with all the images
 */
std::vector<Image> Database::getImages() const {
    return this->_images;
}

/**
 * \param images a vector of images
 */
void Database::setImages(const std::vector<Image> &images) {
    this->_images = images;
}

/**
 * \param image an image
 */
void Database::addImage(const Image &image) {
    this->_images.push_back(image);
}

std::ostream &operator<<(std::ostream &stream, const Database &database) {
    int i;
    for(i = 0; i < database.getImages().size(); i++) {
        stream << database.getImages().at(i).getImageDescriptor() << std::endl;
    }
    return stream;
}
