#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class	Weapon {
public:
	std::string&	getType(void);
	void			setType(const std::string type);

	Weapon();
	Weapon(std::string type);
	Weapon	weapon(const Weapon& other);
	Weapon&	operator=(const Weapon& other);
	~Weapon();
private:
	std::string	_type;
};
#endif

