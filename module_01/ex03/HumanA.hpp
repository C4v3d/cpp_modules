#ifndef	HUMAN_A_H
# define HUMAN_A_H

#include "Weapon.hpp"

class	HumanA {
public:
	void	attack();

	HumanA();
	HumanA(const std::string name, Weapon weapon);
	HumanA	Human(const HumanA& other);
	HumanA&	operator=(const HumanA& other);
	~HumanA();
private:
	Weapon		_weapon;
	std::string	_name;

};

#endif
