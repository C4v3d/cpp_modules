#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"


class	WrongCat : virtual public WrongAnimal {
	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		WrongCat&	operator=(const WrongCat& other);
		~WrongCat();
	private:
		void	makeSound(void) const;
};

#endif
