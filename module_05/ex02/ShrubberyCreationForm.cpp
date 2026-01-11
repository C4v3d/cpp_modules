#include "ShrubberyCreationForm.hpp"
#include <iostream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name): 
	AForm(name, 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) {
	try {
		AForm::execute(executor);
	}
	catch (int err) {
		if (err == 1)
			std::cout << "Form must be signed to be executed" << std::endl;
	if (err == 2)
			std::cout << "Executor doesn't meet the requiered grade" << std::endl;
	}
}
