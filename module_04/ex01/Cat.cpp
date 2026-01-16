#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat"), _brain(new Brain) {
	std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal("Cat") {
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = other;
}

Cat&	Cat::operator=(const Cat& other) {
	std::cout << "Copy assignement Cat constructor called" << std::endl;
	if (this != &other) {
		type = other.type;
		_brain = new Brain(*other._brain);

	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat desctructor called" << std::endl;
	delete _brain;
}

void	Cat::makeSound(void) const {
	std::cout << "Mew Mew" << std::endl;
}

const std::string&	Cat::getIdea(size_t const & i) const {
	return (_brain->getIdea(i));
}

void	Cat::setIdea(std::string const & idea) const {
	_brain->setIdea(idea);
}