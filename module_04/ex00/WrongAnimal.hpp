#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

#include <string>

class	WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const std::string& wrongType);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

		std::string	getType(void) const;
		virtual void		makeSound(void) const;
};

#endif
