#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog"), _brain(new Brain) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal("Dog") {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignement called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf Wouf" << std::endl;
}
