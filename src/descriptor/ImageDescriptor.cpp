#include "ImageDescriptor.h"

ImageDescriptor::ImageDescriptor(const int id, const std::string &path, const std::string &title, const std::string &source, const std::string &author, const int weight) {
    this->_id = id;
    this->_path = path;
    this->_title = title;
    this->_source = source;
    this->_author = author;
    this->_weight = weight;
}

int ImageDescriptor::getId() const {
    return this->_id;
}

std::string ImageDescriptor::getPath() const {
    return this->_path;
}

std::string ImageDescriptor::getTitle() const {
    return this->_title;
}

std::string ImageDescriptor::getSource() const {
    return this->_source;
}

std::string ImageDescriptor::getAuthor() const {
    return this->_author;
}

int ImageDescriptor::getWeight() const {
    return this->_weight;
}

void ImageDescriptor::setId(const int id) {
    this->_id = id;
}

void ImageDescriptor::setPath(const std::string &path) {
    this->_path = path;
}

void ImageDescriptor::setTitle(const std::string &title) {
    this->_title = title;
}

void ImageDescriptor::setSource(const std::string &source) {
    this->_source = source;
}

void ImageDescriptor::setAuthor(const std::string &author) {
    this->_author = author;
}

void ImageDescriptor::setWeight(const int weight) {
    this->_weight = weight;
}

std::ostream &operator<<(std::ostream &stream, const ImageDescriptor &descriptor) {
    stream << descriptor.getId() << ": " << descriptor.getTitle() << ", " << descriptor.getPath() << ", " << descriptor.getSource() << ", " << descriptor.getWeight();
    return stream;
}
