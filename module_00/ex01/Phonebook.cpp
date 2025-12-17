#include "Phonebook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Phonebook::Phonebook (void): pos(0), nContacts(0) {
}

Phonebook::~Phonebook (void) {
}

std::string	Phonebook::FormatText(std::string s) const{
	if (s.size() > 10) {
		s.resize(9);
		s.push_back('.');
	}
	return (s);
}

void	Phonebook::DisplayContactById(const Contact contact) const {

	std::cout << std::setfill(' ');
	std::cout << "First Name" << std::setw(10) << ": " << std::right << contact.GetFirstName() << std::endl;
	std::cout << "Last Name" << std::setw(10) << ": " << contact.GetLastName() << std::endl;
	std::cout << "Nickname" << std::setw(10) << ": " << contact.GetNickName() << std::endl;
	std::cout << "Phone Number" << std::setw(10) << ": " << contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret" << std::setw(10) << ": " << contact.GetDarkestSecret() << std::endl;
}

void	Phonebook::DisplayContactList(const Contact contact[8]) const {
	std::string	col1;
	std::string	col2;
	std::string	col3;
	std::string	col4;

	std::cout << "+" << std::setw(44) << std::setfill('-') << "+" << std::endl;
	for (size_t i = 0; i < this->nContacts; i++) {
		col1 = '1' + i;
		col2 = this->FormatText(contact[i].GetFirstName());
		col3 = this->FormatText(contact[i].GetLastName());
		col4 = this->FormatText(contact[i].GetNickName());
		std::cout << std::setfill(' ') <<  "|" << std::setw(10) << col1
			<< "|" << std::setw(10) << col2
			<< "|" << std::setw(10) << col3
			<< "|" << std::setw(10) << col4
			<< "|" << std::endl;
	}
	std::cout << "+" << std::setfill('-') << std::setw(44) << "+" << std::endl;

}

void	Phonebook::AddContact (void) {
	std::string	data;

	if (this->nContacts == 8) {
		std::cout << "Reached maximum contacts ! Deleting oldest one" << std::endl;
		this->pos = 0;
	}
	std::cout << "Enter First Name :" << std::endl;
	getline(std::cin, data);
	this->contacts[this->pos].SetFirstName(data);
	std::cout << "Enter Last Name :" << std::endl;
	getline(std::cin, data);
	this->contacts[this->pos].SetLastName(data);
	std::cout << "Enter Nickname :" << std::endl;
	getline(std::cin, data);
	this->contacts[this->pos].SetNickName(data);
	std::cout << "Enter Phone number :" << std::endl;
	getline(std::cin, data);
	this->contacts[this->pos].SetPhoneNumber(data);
	std::cout << "Enter Darkest Secret :" << std::endl;
	getline(std::cin, data);
	this->contacts[this->pos].SetDarkestSecret(data);

	this->pos++;
	if (this->nContacts < 8)
		this->nContacts++;
}

void	Phonebook::SearchContact(void) const {
	std::string	input;
	int		index;

	if (this->nContacts == 0) {
		std::cout << "Empty Phonebook ! Use ADD to add contacts to your Phonebook." << std::endl;
		return ;
	}
	this->DisplayContactList(this->contacts);
	std::cout << "Enter the index of the contact you are looking for :" << std::endl;
	getline(std::cin, input);
	if (input.empty()) {
		std::cout << "You must specify an index to select a contact" << std::endl;
		return ;
	}
	index = atoi(input.c_str());
	if (index == 0) {
		std::cout << "Incorrect value." << std::endl;
		return ;
	}
	if (index >= 0 && index <= (int)this->nContacts)
		this->DisplayContactById(this->contacts[index - 1]);
	else
		std::cout << "There is no contact associeted with this index." << std::endl;
}
