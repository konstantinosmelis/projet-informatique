#ifndef USER_H
#define USER_H

#include <string>

class User {
	private:
		std::string _username, _password; /** The users's username and password */
		bool _isAdmin = false; /** The users's role (by default he is not an administrator) */

	public:
		User();
		User(const std::string &, const std::string &);

		/**
		 * \brief Get the users's username
		 */
		std::string getUsername() const;

		/**
		 * \brief Get the users's password
		 */
		std::string getPassword() const;

		/**
		 * \brief Check if the users is an administrator
		 */
		bool isAdmin() const;

		/**
		 * \brief Set the users's username
		 */
		void setUsername(const std::string &);

		/**
		 * \brief Set the users's password
		 */
		void setPassword(const std::string &);

		/**
		 * \brief Set administator rights
		 */
		void setAdmin(const bool);

		/**
		 * \brief Check if the users can login to the app
		 */
		bool verifyLogin(const std::string &);
};

#endif //USER_H
