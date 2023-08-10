#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);
	~DiamondTrap(void);
	DiamondTrap &operator=(const DiamondTrap &DiamondTrap);

	void	whoAmI();
	void	attack(std::string target);
};

#endif