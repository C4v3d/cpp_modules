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
		_brain = new Brain(*other._brain);
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

const std::string&	Dog::getIdea(size_t const & i) const {
	return (_brain->getIdea(i));
}

void	Dog::setIdea(std::string const & idea) const {
	_brain->setIdea(idea);
}