#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class	Weapon {
public:
	const std::string&	getType(void);
	void			setType(std::string type);

	Weapon();
	Weapon(std::string type);
	Weapon	weapon(const Weapon& other);
	Weapon&	operator=(const Weapon& other);
	~Weapon();
private:
	std::string	_type;
};
#endif

