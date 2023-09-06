#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	this->_name = "Unnamed";
    ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "*Default DiamondTrap constructed*" << std::endl;
}
 
DiamondTrap::DiamondTrap(std::string name){
	
	std::cout << name << " DiamondTrap constructor called" << std::endl;
	this->_name = name;
    ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	*this = copy;
    std::cout << "Copy DiamondTrap " << _name << " constructed!" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& DiamondTrap) {
	std::cout << "DiamondTrap Assignment operator called" << std::endl;
	ClapTrap::operator=(DiamondTrap);
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "*DiamondTrap " << _name << " destructed*" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << this->_name << " and my clap name is " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(std::string target) {
	ScavTrap::attack(target);
}