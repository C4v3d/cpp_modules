#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"){
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal("Cat") {
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Copy assignement Cat constructor called" << std::endl;
	if (this != &other) {
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat desctructor called" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Mew Mew" << std::endl;
}
