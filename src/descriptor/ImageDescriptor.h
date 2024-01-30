#ifndef IMAGEDESCRIPTOR_H
#define IMAGEDESCRIPTOR_H

#include <iostream>
#include <string>

class ImageDescriptor {
    private:
    int _id, _weight;
    std::string _path, _title, _source, _author, _access;
    std::string _descriptorPath;//to handle delete and update functions directly inside the file.

    public:
        // Constructors
        ImageDescriptor();
        ImageDescriptor(const int, const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const int);
        ImageDescriptor(const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const int);
        ImageDescriptor(const int ,const std::string &, const std::string &, const std::string &, const std::string &, const std::string &, const int, const std::string &);

        // Getters
        int getId() const;
        std::string getPath() const;
        std::string getTitle() const;
        std::string getSource() const;
        std::string getAuthor() const;
        std::string getAccessLevel() const;
        int getWeight() const;
        std::string getDescriptorPath() const;

        // Settters
        void setId(const int);
        void setPath(const std::string &);
        void setTitle(const std::string &);
        void setSource(const std::string &);
        void setAuthor(const std::string &);
        void setAccessLevel(const std::string &);
        void setWeight(const int);
        void save(const std::string&) const;

        void setDescriptorPath(const std::string &);
};

std::ostream &operator<<(std::ostream &, const ImageDescriptor &);

#endif //IMAGEDESCRIPTOR_H
