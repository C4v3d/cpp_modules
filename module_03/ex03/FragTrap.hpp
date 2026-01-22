#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {
	public:
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap(void);

		void	highFivesGuys(void);
	protected:
		static const int	_defHitPoints = 100;
		static const int	_defEnergyPoints = 100;
		static const int	_defAttackDamage = 30;
};

#endif
