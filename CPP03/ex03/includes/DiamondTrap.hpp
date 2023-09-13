#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {
private:
	std::string _name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string const name);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap &operator=(const DiamondTrap &DiamondTrap);
	~DiamondTrap(void);

	void		whoAmI();
	void		attack(std::string target);
	void		printTrap();
};

#endif