#include "ImageDescriptor.h"

#include "../image/Image.h"

#include <fstream>

ImageDescriptor::ImageDescriptor() {
}

/**
 * \param id an identifier
 * \param path the image's path
 * \param title the image's title
 * \param source this image's source
 * \param author this image's author
 * \param access the image's access level (public or private)
 * \param weight this image's weight
 */
ImageDescriptor::ImageDescriptor(const int id, const std::string &path, const std::string &title, const std::string &source, const std::string &author, const std::string &access, const int weight) {
    this->_id = id;
    this->_path = path;
    this->_title = title;
    this->_source = source;
    this->_author = author;
    this->_access = access;
    this->_weight = weight;
}

/**
 * \param path the image's path
 * \param title the image's title
 * \param source this image's source
 * \param author this image's author
 * \param access the image's access level (public or private)
 * \param weight this image's weight
 */
ImageDescriptor::ImageDescriptor(const std::string &path, const std::string &title, const std::string &source, const std::string &author, const std::string &access, const int weight) {
    this->_path = path;
    this->_title = title;
    this->_source = source;
    this->_author = author;
    this->_access = access;
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

std::string ImageDescriptor::getAccessLevel() const {
    return this->_access;
}

int ImageDescriptor::getWeight() const {
    return this->_weight;
}

/**
 * \param id an identifier
 */
void ImageDescriptor::setId(const int id) {
    this->_id = id;
}

/**
 * \param path a path to the image's location
 */
void ImageDescriptor::setPath(const std::string &path) {
    this->_path = path;
}

/**
 * \param title a title for the image
 */
void ImageDescriptor::setTitle(const std::string &title) {
    this->_title = title;
}

/**
 * \param source the image's source
 */
void ImageDescriptor::setSource(const std::string &source) {
    this->_source = source;
}

/**
 * \param author the image's author
 */
void ImageDescriptor::setAuthor(const std::string &author) {
    this->_author = author;
}

/**
 * \param access the image's access level
 */
void ImageDescriptor::setAccessLevel(const std::string &access) {
    this->_access = access;
}

/**
 * \param weight the image's weight
 */
void ImageDescriptor::setWeight(const int weight) {
    this->_weight = weight;
}

/**
 * \param path the path to where the image will be saved
 */
void ImageDescriptor::save(const std::string& path) const {
    std::ofstream outfile;
    outfile.open(path);
    outfile << _path << std::endl;
    outfile << _title << std::endl;
    outfile << _source << std::endl;
    outfile << _author << std::endl;
    outfile << _access << std::endl;
    outfile << _weight << std::endl;
    outfile.close();
}

std::ostream &operator<<(std::ostream &stream, const ImageDescriptor &descriptor) {
    stream << descriptor.getId() << ": " << descriptor.getTitle() << ", " << descriptor.getPath() << ", " << descriptor.getSource() << ", " << descriptor.getWeight();
    return stream;
}
