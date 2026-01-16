#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Brain;

class Dog : virtual public Animal {
	public :
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();
		const std::string&	getIdea(size_t const & i) const;
		void				setIdea(std::string const & idea) const;
	
	private:
		void	makeSound(void) const;
		Brain*	_brain;
};
#endif
