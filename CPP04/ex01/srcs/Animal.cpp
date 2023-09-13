#include "Animal.hpp"

Animal::Animal() {
	this->_type = "Animal";
	std::cout << "* Animal default constructor called *" << std::endl;
}

Animal::~Animal() {
	std::cout << "* Animal default deconstructor called *" << std::endl;
}

Animal::Animal(const Animal &animal) {
	*this = animal;
	std::cout << "* Animal copy constructor called *" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	std::cout << "* Animal assignment operator called *" << std::endl;
	this->_type = animal._type;
	return (*this);
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void Animal::makeSound() const {
	std::cout << "Animal sounds..." << std::endl;
}

std::string	Animal::getType() const {
	return (this->_type);
}

void Animal::getIdea(int index) const {
	(void)index;
}

void	Animal::printBrainAddress() {
	std::cout << "Animals don't have brains..." << std::endl;
}