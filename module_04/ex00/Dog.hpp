#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : virtual public Animal {
	public :
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();
	
	private:
		void	makeSound(void) const;
};
#endif
