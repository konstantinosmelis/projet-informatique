#ifndef USER_H
#define USER_H

#include <string>
#include "UserRight.h"

class User {
	private:
		std::string _userName;
		std::string _userPassword;
		UserRight _userRights;

	public:
		User(const std::string &, const std::string &, const UserRight &);

		std::string getUserName() const;
		std::string getUserPassword() const;
		UserRight getUserRights() const;

		void setUserName(const std::string &);
		void setUserPassword(const std::string &);
		void setUserRights(const UserRight);

		bool verifyLogin(const std::string , const std::string) const;
};

#endif //USER_H
