#include "Contact.hpp"
#include <iostream>

Contact::Contact(void) {
}

Contact::~Contact(void) {
}

void Contact::SetFirstName(std::string fname) {
	if (fname.empty())
		Contact::_firstName = '*';
	else
		Contact::_firstName = fname;
}

void Contact::SetLastName(std::string lname) {
	if (lname.empty())
		Contact::_lastName = '*';
	else
		Contact::_lastName = lname;
}

void Contact::SetNickName(std::string nname) {
	if (nname.empty())
		Contact::_nickName = '*';
	else
		Contact::_nickName = nname;
}

void Contact::SetPhoneNumber(std::string phoneNumber) {
	if (phoneNumber.empty())
		Contact::_phoneNumber = '*';
	else
		Contact::_phoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(std::string darkestSecret) {
	if (darkestSecret.empty())
		Contact::_darkestSecret = '*';
	else
		Contact::_darkestSecret = darkestSecret;
}

std::string	Contact::GetFirstName() const{
	return (Contact::_firstName);
}

std::string	Contact::GetLastName() const{
	return (Contact::_lastName);
}

std::string	Contact::GetNickName() const{
	return (Contact::_nickName);
}

std::string	Contact::GetPhoneNumber() const{
	return (Contact::_phoneNumber);
}

std::string	Contact::GetDarkestSecret() const{
	return (Contact::_darkestSecret);
}
