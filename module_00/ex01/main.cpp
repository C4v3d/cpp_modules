#include "Phonebook.hpp"
#include <iostream>
#include <cstdlib>

int	GetOperationCode(std::string s) {
	if (s == "ADD")
		return (1);
	if (s == "SEARCH")
     		return (2);
	if (s == "EXIT")
		return (3);
	return (0);
}

int	main(void){
	Phonebook	book;
	std::string	opt;

	std::cout << "Welcome to Phonebook !" << std::endl;
	while (std::cin) {
		std::cout << "Enter one of the options (ADD, SEARCH, EXIT)" << std::endl;
		getline(std::cin, opt);
		switch(GetOperationCode(opt)) {
	 		case 1:
				book.AddContact();
				break ;
			case 2:
				book.SearchContact();
				break ;
			case 3:
				exit(0);
			default:
				std::cout << "Unkown option" << std::endl;
		}
	}

	return (0);
}
