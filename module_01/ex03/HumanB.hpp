#ifndef	HUMAN_B_H
# define HUMAN_B_H

#include "Weapon.hpp"

class	HumanB {
public:
	Weapon		*weapon;
	std::string	name;

	HumanB(const std::string name);
	HumanB	Human(const HumanB& other);
	HumanB&	operator=(const HumanB& other);
	~HumanB();
private:
	void	attack();

};

#endif
