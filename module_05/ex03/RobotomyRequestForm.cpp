#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm():
	AForm("Robotomy Request Form", 72, 45),
	_target("You")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target):
	AForm("Robotomy Request Form", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & other):
	AForm(other.getName(), other.getSignGrade(), other.getExecGrade()), _target(other._target) {
		*this = other;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm & other) {
	(void)other;
	std::cout << "Forms are const thus it cannot change its value" << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::executeForm() const {
	srand(time(0));
	int	r = rand();
	std::cout << "VrrrrrrRRrrRrrrr.... BRRRrrrr.... VrrrrRRRRRrr...." << std::endl;
	if (r % 2)
		std::cout << _target << " has been successfully robotomized !" << std::endl;
	else
		std::cout << "The robotomy has failed..." << std::endl;
}
