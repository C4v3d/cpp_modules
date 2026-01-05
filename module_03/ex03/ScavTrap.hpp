#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	public:
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap(void);

		void	attack(const std::string& target);
		void	guardGate(void);
	protected:
		static const int		_defHitPoints = 100;
		static const int		_defEnergyPoints = 50;
		static const int		_defAttackDamage = 20;
};

#endif
