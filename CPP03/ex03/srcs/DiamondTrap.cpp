#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
	this->_name = "Unnamed";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::getHitPoints();
	_energyPoints = ScavTrap::getEnergyPoints();
	_attackDamage = FragTrap::getAttackDamage();
	std::cout << "*Default DiamondTrap constructed*" << std::endl;
}
 
DiamondTrap::DiamondTrap(std::string name) : ScavTrap(), FragTrap() {
	std::cout << name << " DiamondTrap constructor called" << std::endl;
	this->_name = name;
    ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints = ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	this->_name = copy._name;
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

void	DiamondTrap::printTrap() {
	std::cout << "Name = " << this->_name << std::endl;
	std::cout << "Hitpoints (Frag=100) = " << this->_hitPoints << std::endl;
	std::cout << "Energypoints (Scav=50) = " << this->_energyPoints << std::endl;
	std::cout << "AttackDamage (Frag=30) = " << this->_attackDamage << std::endl << std::endl;
}