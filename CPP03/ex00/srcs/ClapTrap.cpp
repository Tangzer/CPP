#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_name = name;
	std::cout << "Default ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
    this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	this->_name = other._name;
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
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is dead and cannot attack" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
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
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy point left" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repaired " << amount << " of hit point and now has " << _hitPoints << " hit points" << std::endl;
}