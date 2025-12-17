#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
public :
	Zombie	(void);
	Zombie	(std::string name);
	Zombie	(const Zombie &other);
	Zombie	&operator=(const Zombie &other);
	~Zombie	(void);

	void	announce(void);
private:
	std::string	_name;
};

#endif

