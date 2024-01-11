#ifndef USER_H
#define USER_H

#include <string>

class User {
	private:
		std::string _username, _password; /** The user's username and password */
		bool _isAdmin = false; /** The user's role (by default he is not an administrator) */

	public:
		User(const std::string &, const std::string &);

		/**
		 * \brief Get the user's username
		 */
		std::string getUsername() const;

		/**
		 * \brief Get the user's password
		 */
		std::string getPassword() const;

		/**
		 * \brief Check if the user is an administrator
		 */
		bool isAdmin() const;

		/**
		 * \brief Set the user's username
		 */
		void setUsername(const std::string &);

		/**
		 * \brief Set the user's password
		 */
		void setPassword(const std::string &);

		/**
		 * \brief Set administator rights
		 */
		void setAdmin(const bool);

		/**
		 * \brief Check if the user can login to the app
		 */
		bool verifyLogin(const std::string &);
};

#endif //USER_H
