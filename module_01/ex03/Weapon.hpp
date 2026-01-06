#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class	Weapon {
public:
	const std::string&	getType(void) const;
	void		setType(const std::string type);

	Weapon();
	Weapon(const std::string& type);
	~Weapon();
private:
	std::string	_type;
};
#endif

