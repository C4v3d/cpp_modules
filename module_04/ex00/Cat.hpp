#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : virtual public Animal { 
	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();
	private:
		void	makeSound(void) const;
};

#endif
