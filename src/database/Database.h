#ifndef DATABSE_H
#define DATABSE_H

#include <vector>
#include "../image/Image.h"

class Database {
    private:
        std::vector<Image> _images; /** A vector storing all images */

    public:
        /**
         * \brief Create a database storing all the images
         */
        Database();

        /**
         * \brief Load database using files sotred in a specified directory
         */
        void load(const std::string &);

        /**
         * \brief Get all the images stored in the database
         */
        std::vector<Image> getImages() const;

        /**
         * \brief Define the images in database
         */
        void setImages(const std::vector<Image> &);

        /**
         * \brief Add new images in the database
         */
        void addImage(const Image &);
};

std::ostream &operator<<(std::ostream &, const Database &);

#endif //DATABSE_H
