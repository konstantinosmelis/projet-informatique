#include "User.h"

#include <filesystem>
#include <fstream>

User::User() {

}

User::User(const std::string &username, const std::string &password) {
    this->_username = username;
    this->_password = password;
}

/**
 * \return the users's username
 */
std::string User::getUsername() const {
    return this->_username;
}

/**
 * \return the users's password
 */
std::string User::getPassword() const {
    return this->_password;
}

/**
 * \return whether the users is an administrator or not
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
 * \param path The directory where users files are stored
 * \return whether the users can login or not
 */
bool User::verifyLogin(const std::string &path) {
    std::ifstream file;
    std::string userPath = path + this->_username;
    std::string password;

    // Check if the users file exists
    if(std::filesystem::exists(userPath)) {
        // If the file exists te users can login with the correct password
        file.open(userPath);
        file >> password;
        file >> std::boolalpha >>this->_isAdmin; // Check if the users is an admin
        file.close();
        return this->_password == password; // If passwords match the users can login
    }
    return false; // If the file doesn't exist the users doesn't exist either
}
