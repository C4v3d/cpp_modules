#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog") {
	std::cout << "Default constructor of Dog called" << std::endl;
}

Dog::Dog(const Dog& other): Animal("Dog") {
	std::cout << "Copy constructor of Dog called" << std::endl;
	*this = other;
}

Dog&	Dog::operator=(const Dog& other) {
	std::cout << "Copy assignement of Dog called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Destructor of Dog called" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf Wouf" << std::endl;
}
