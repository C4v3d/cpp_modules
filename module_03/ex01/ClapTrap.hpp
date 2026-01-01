#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <string>

class ClapTrap {
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap(void);

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		friend std::ostream&	operator<<(std::ostream& output, const ClapTrap& clapTrap);

		std::string	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	private:
		// std::string	_name;
		// unsigned int	_hitPoints;
		// unsigned int	_energyPoints;
		// unsigned int	_attackDamage;
};
#endif
