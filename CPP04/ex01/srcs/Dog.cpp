#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "* Dog default constructor called *" << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog() {
	std::cout << "* Dog default deconstructor called *" << std::endl;
	delete this->_brain;
	printBrainAddress();
}

Dog::Dog(const Dog &dog) : Animal() {
	std::cout << "* Dog copy constructor called *" << std::endl;
	this->_brain = new Brain();
	*(this->_brain) = *(dog._brain);
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "* Dog assignment operator called *" << std::endl;
	this->_type = dog._type;
	*(this->_brain) = *(dog._brain);
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Dog sounds..." << std::endl;
}

void Dog::printBrainAddress() {
	std::cout << &this->_brain << std::endl;
}

void Dog::getIdea(int index) const {
	std::cout << this->_brain->getIdea(index) << std::endl;
}

void Dog::setIdea(std::string idea, int index) {
	this->_brain->setIdea(idea, index);
}