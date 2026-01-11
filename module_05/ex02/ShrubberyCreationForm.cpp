#include "ShrubberyCreationForm.hpp"
#include <iostream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name): 
	AForm(name, 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
	try {
		AForm::execute(executor);
		std::cout << "I can sign !" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
