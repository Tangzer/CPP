#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
	this->_name = "Unnamed";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "*Default FragTrap constructed!*" << std::endl;
}

FragTrap::FragTrap(std::string name) {
	std::cout << _name << " FragTrap constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) {
	*this = copy;
	std::cout << "Copy FragTrap " << _name << " constructed!" << std::endl;

}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
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