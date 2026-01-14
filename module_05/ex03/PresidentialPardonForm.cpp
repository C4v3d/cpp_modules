#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(std::string const & target):
	AForm("Presidential Pardon Form", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other):
	AForm(other._target, other.getSignGrade(), other.getExecGrade()), _target(other._target) {
		*this = other;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & other) {
	(void)other;
	std::cout << "Forms are constant object, data will not changes" << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	try {
		AForm::execute(executor);
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		throw ;
	}
}
