#include "User.h"

User::User(const std::string& userName, const std::string& userPassword, const UserRight& userRights)
{
	this->_userName = userName;
	this->_userPassword = userPassword;
	this->_userRights = userRights;
}

std::string User::getUserName() const
{
	return this->_userName;
}

std::string User::getUserPassword() const
{
	return this->_userPassword;
}

UserRight User::getUserRights() const
{
	return this->_userRights;
}



void User::setUserName(const std::string& userName)
{
	this->_userName = userName;
}

void User::setUserPassword(const std::string& userPassword)
{
	this->_userPassword = userPassword;
}

void User::setUserRights(const UserRight userRights)
{
	this->_userRights = userRights;
}

bool User::verifyLogin(const std::string userName, const std::string password) const
{
	if (this->_userName == userName && this->_userPassword == password) {
		return true;
	}
	return false;
}
