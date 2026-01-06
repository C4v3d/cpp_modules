#ifndef	HUMAN_B_H
# define HUMAN_B_H

#include "Weapon.hpp"

class	HumanB {
public:
	void	attack() const;
	void	setWeapon(Weapon& weapon);

	HumanB(const std::string& name);
	~HumanB();
private:
	std::string	_name;
	Weapon*		_weapon;

};

#endif
