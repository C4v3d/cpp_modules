#ifndef	HUMAN_A_H
# define HUMAN_A_H

#include "Weapon.hpp"

class	HumanA {
public:
	void	attack() const;

	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();
private:
	std::string	_name;
	Weapon&		_weapon;

};

#endif
