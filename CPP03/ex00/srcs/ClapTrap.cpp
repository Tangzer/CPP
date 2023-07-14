#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	this->_name = "Unnamed";
    this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << " Default ClapTrap constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
    this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << _name << " ClapTrap " << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "Copy ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << _name << " assigned!" << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructed" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void ClapTrap::attack(const std::string &target) {
	if (this->_hitPoints > 0 and this->_energyPoints > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << std::endl;
		std::cout << target << " loses " << this->_attackDamage << " hit points" << std::endl;
		ClapTrap::useEnergyPoint(this->_energyPoints);
	}
	else if (this->_hitPoints <= 0)
		std::cout << "ScavTrap " << this->_name << " is already dead. Leave it alone!" << std::endl << std::endl;
	else
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack" << std::endl;
		std::cout << "Energy points left: " << this->_energyPoints << std::endl << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead" << std::endl;
		return;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " point of damage and now has " << _hitPoints << " hit points left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
		return;
	}
	else if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy point left" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repaired " << amount << " of hit point and now has " << _hitPoints << " hit points" << std::endl;
}

void	ClapTrap::useEnergyPoint(int& energyPoints)
{
	energyPoints = energyPoints - 1;
	std::cout << "Energy points left: " << energyPoints << std::endl << std::endl;
}