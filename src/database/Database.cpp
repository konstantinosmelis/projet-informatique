#include "Database.h"

#include <filesystem>
#include <fstream>
#include <vector>
#include <QDebug>

Database::Database() {
}

/**
 * \param directoryName the path to thie directory containing the descriptor files
 */
void Database::load(const std::string &directoryName) {
    int number_of_images = (int) this->_images.size();
    std::filesystem::directory_iterator direcotry;
    std::ifstream file;
    std::string path;
    std::string line;
    std::vector<std::string> lines;

    direcotry = std::filesystem::directory_iterator(directoryName);
    for(const auto &entry : direcotry) {
        path = entry.path().string();

        file.open(path);
        if(!file.is_open()) {
            std::cerr << "[Error] - Failed to open file " << path << std::endl;
            continue;
        }

        lines = std::vector<std::string>();
        while(std::getline(file, line)) {
            lines.push_back(line);
        }
        this->addImage(Image(ImageDescriptor(++number_of_images, lines[0], lines[1], lines[2], lines[3], lines[4], std::stoi(lines[5]), path)));
        file.close();
    }
}

/**
 * \return a vector with all the images
 */
std::vector<Image> Database::getImages() const {
    return this->_images;
}

/**
 * \param id a image's identifier
 * \return the image with the given id
 */
Image Database::getImageById(const int id) {
    for (Image image : this->_images) {
        if (image.getImageDescriptor().getId() == id) {
            return image;
        }
    }
    // If no matching id is found, return a default-constructed Image
    return Image();
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
    for(i = 0; i < (int) database.getImages().size(); i++) {
        stream << database.getImages().at(i).getImageDescriptor() << std::endl;
    }
    return stream;
}
void Database::deleteImageById(const int id) {
    auto it = std::remove_if(_images.begin(), _images.end(), [id](const Image& img) {
        return img.getImageDescriptor().getId() == id;
    });

    _images.erase(it, _images.end());
}

