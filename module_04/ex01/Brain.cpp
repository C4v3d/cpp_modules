#include "Brain.hpp"
#include <iostream>
#include <string>

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
};

Brain::Brain(const Brain& other) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain&	Brain::operator=(const Brain& other) {
	std::cout << "Brain copy assignement called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

const std::string&	Brain::getIdea(size_t const & i) const {
	if (i > 99 || i > _index) {
		std::cout << "Index specified is out of bound" << std::endl;
		return NULL;
	}
	return (_ideas[i]);
}

void	Brain::setIdea(std::string const & idea) {
	if (_index == 99) {
		std::cout << "Brain is full of ideas" << std::endl;
		return ;
	}
	else {
		_ideas[_index] = idea;
		_index++;
	}
}