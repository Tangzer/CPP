#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "* Dog default constructor called *" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal() {
	std::cout << "* Dog copy constructor called *" << std::endl;
	*this = other;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "* Dog assignment operator called *" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

Dog::~Dog() {
	std::cout << "* Dog default deconstructor called *" << std::endl;
	delete(this->_brain);
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void Dog::makeSound() const {
	std::cout << "Dog sounds..." << std::endl;
}

void Dog::printBrainAddress() {
	std::cout << &this->_brain << std::endl;
}

void Dog::addIdea(std::string idea, int index) {
	this->_brain->addIdea(idea, index);
}

void Dog::getIdea(int index) const
{
	std::cout << this->_brain->getIdea(index) << std::endl;
}