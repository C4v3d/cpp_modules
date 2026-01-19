#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Brain;

class Cat : virtual public Animal { 
	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		const std::string&	getIdea(size_t const & i) const;
		void				setIdea(std::string const & idea) const;
		void	makeSound(void) const;
	private:
		Brain*	_brain;
};

#endif
