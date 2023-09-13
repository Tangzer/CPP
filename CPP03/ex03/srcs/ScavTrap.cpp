#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	this->_name = "Unnamed";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "*Default ScavTrap constructed!*" << std::endl;
//	printTrap();
}

ScavTrap::ScavTrap(std::string name) {
	std::cout << _name <<" ScavTrap constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_name = name;
}

ScavTrap::ScavTrap(const ScavTrap &copy) {
	*this = copy;
	std::cout << "Copy ScavTrap " << _name << " constructed!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "ScavTrap " << _name << " assigned" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "*ScavTrap " << _name << " destructed*" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void 	ScavTrap::attack(const std::string &target) {
	if (this->_hitPoints > 0 and this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << std::endl;
		std::cout << target << " loses " << this->_attackDamage << " hit points" << std::endl;
		ClapTrap::useEnergyPoint(this->_name, this->_energyPoints);
	}
	else if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " is already dead. Leave it alone!" << std::endl << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack" << std::endl;
		std::cout << "Energy points left: " << this->_energyPoints << std::endl << std::endl;
	}
}

void	ScavTrap::guardGate() {
	if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " is already dead. Leave it alone!" << std::endl << std::endl;
	else if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack" << std::endl;
		std::cout << "Energy points left: " << this->_energyPoints << std::endl << std::endl;
	}
	else
	{
		if (this->_guardMode)
		{
			this->_guardMode = false;
			std::cout << this->_name << ": Guard mode turned OFF" << std::endl;
		}
		else
		{
			this->_guardMode = true;
			std::cout << this->_name << ": Guard mode turned ON" << std::endl;
		}
	}
}

void	ScavTrap::printTrap() {
	std::cout << "Name = " << this->_name << std::endl;
	std::cout << "Hitpoints (Frag=100) = " << this->_hitPoints << std::endl;
	std::cout << "Energypoints (Scav=50) = " << this->_energyPoints << std::endl;
	std::cout << "AttackDamage (Frag=30) = " << this->_attackDamage << std::endl << std::endl;
}