#include <filesystem>
#include <fstream>
#include <vector>
#include "Database.h"

Database::Database() {
}

/**
 * \param directoryName the path to thie directory containing the descriptor files
 */
void Database::load(std::string &directoryName) {
    int number_of_images = 0;
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
        this->addImage(Image(ImageDescriptor(++number_of_images, lines[0], lines[1], lines[2], lines[3], lines[4], std::stoi(lines[5]))));

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
