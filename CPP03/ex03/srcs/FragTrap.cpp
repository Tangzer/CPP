#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->_name = "Unnamed";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "*Default FragTrap constructed!*" << std::endl;
//	printTrap();
}

FragTrap::FragTrap(std::string name) {
	std::cout << _name << " FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &copy) {
	if (this != &copy)
		*this = copy;
	std::cout << "Copy FragTrap " << _name << " constructed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Assignment operator called" << std::endl;
	if (this != &other)   
        ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void) {
	std::cout << "*FragTrap " << _name << " destructed*" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void FragTrap::highFivesGuys(void) {
	std::cout << this->_name << " would like to high five you. If that's okay with you :)." << std::endl;
}

void FragTrap::printTrap() {
	std::cout << "Name = " << this->_name << std::endl;
	std::cout << "Hitpoints (Frag=100) = " << this->_hitPoints << std::endl;
	std::cout << "Energypoints (Scav=50) = " << this->_energyPoints << std::endl;
	std::cout << "AttackDamage (Frag=30) = " << this->_attackDamage << std::endl << std::endl;
}

unsigned int FragTrap::getHitPoints() {
	return (this->_hitPoints);
}

unsigned int FragTrap::getAttackDamage() {
	return (this->_attackDamage);
}
