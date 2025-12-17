#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class Phonebook {
private:
	Contact		contacts[8];
	size_t		pos;
	size_t		nContacts;
	void		DisplayContactList(const Contact contact[8]) const;
	void		DisplayContactById(const Contact contact) const;
	std::string	FormatText(std::string s) const;

public:
	Phonebook();
	~Phonebook();

	void	AddContact();
	void	SearchContact() const;
};

#endif
