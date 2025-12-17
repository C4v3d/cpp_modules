#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact {
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	// Contact(const Contact &other);
	// Contact& operator=(const Contact &other);
	~Contact();

	void		SetFirstName(std::string fname);
	void		SetLastName(std::string lname);
	void		SetNickName(std::string nname);
	void		SetPhoneNumber(std::string phoneNumber);
	void		SetDarkestSecret(std::string darksetSecret);

	std::string	GetFirstName() const;
	std::string	GetLastName() const;
	std::string	GetNickName() const;
	std::string	GetPhoneNumber() const;
	std::string	GetDarkestSecret() const;
};

#endif
