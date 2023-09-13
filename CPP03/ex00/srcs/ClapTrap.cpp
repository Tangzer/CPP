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
	if (this->_energyPoints > 0 and this->_hitPoints > 0)
	{
		std::cout << this->_name << " attacks " << target << std::endl;
		useEnergyPoint(_name, _energyPoints);
	}
	else if (this->_hitPoints <= 0)
		std::cout << this->_name << " is already dead. Leave it alone!" << std::endl << std::endl;
	else
	{
		std::cout << this->_name << " cannot attack" << std::endl;
		std::cout << _name << "'s energy points left: " << this->_energyPoints << std::endl << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints > 0)
	{
		this->_hitPoints = this->_hitPoints - amount;
		std::cout << this->_name << " gets attacked" << std::endl;
		std::cout << this->_name << " loses " << amount << " hit points" << std::endl;
		if (this->_hitPoints <= 0)
			std::cout << this->_name << " died of his injuries" << std::endl;
		else
			std::cout << this->_name << "'s hit points remaining: " << _hitPoints << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << this->_name << " is already dead. Leave it alone!" << std::endl << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints > 0)
	{
		this->_hitPoints = this->_hitPoints + amount;
		this->_energyPoints -= 1;
		std::cout << this->_name << " gets repaired" << std::endl;
		std::cout << this->_name << " gains " << amount << " hit points" << std::endl;
		std::cout << this->_name << "'s hit points remaining: " << _hitPoints << std::endl;
		this->_energyPoints -= 1;
		std::cout << this->_name << " lost 1 energy point" << std::endl;
		std::cout << std::endl;
	}
	else
		std::cout << this->_name << " is already dead. Leave it alone!" << std::endl << std::endl;
}

void ClapTrap::useEnergyPoint(std::string &name, int &energyPoints) {
	energyPoints = energyPoints - 1;
	std::cout << name << "'s energy points left: " << energyPoints << std::endl << std::endl;
}