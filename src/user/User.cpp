#include <filesystem>
#include <fstream>
#include "User.h"

User::User(const std::string &username, const std::string &password) {
    this->_username = username;
    this->_password = password;
}

/**
 * \return the user's username
 */
std::string User::getUsername() const {
    return this->_username;
}

/**
 * \return the user's password
 */
std::string User::getPassword() const {
    return this->_password;
}

/**
 * \return whether the user is an administrator or not
 */
bool User::isAdmin() const {
    return this->_isAdmin;
}

/**
 * \param username a username
 */
void User::setUsername(const std::string &username) {
    this->_username = username;
}

/**
 * \param password a password
 */
void User::setPassword(const std::string &password) {
    this->_password = password;
}

/**
 * \param isAdmin whether or not the iuser is going to be an administrator
 */
void User::setAdmin(const bool isAdmin) {
    this->_isAdmin = isAdmin;
}

/**
 * \param path The directory where user files are stored
 * \return whether the user can login or not
 */
bool User::verifyLogin(const std::string &path) {
    std::ifstream file;
    std::string userPath = path + this->_username;
    std::string password;
    // Check if the user file exists
    if(std::filesystem::exists(userPath)) {
        // If the file exists te user can login with the correct password
        file.open(userPath);
        file >> password;
        file >> this->_isAdmin; // Check if the user is an admin
        file.close();
        return this->_password == password; // If passwords match the user can login
    }
    return false; // If the file doesn't exist the user doesn't exist either
}
