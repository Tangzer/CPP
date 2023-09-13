#include "Dog.hpp"

Dog::Dog() {
	this->_type = "Dog";
	std::cout << "* Dog default constructor called *" << std::endl;
}

Dog::~Dog() {
	std::cout << "* Dog default deconstructor called *" << std::endl;
}

Dog::Dog(const Dog &other) {
	*this = other;
	std::cout << "* Dog copy constructor called *" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "* Dog assignment operator called *" << std::endl;
	this->_type = other._type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Wouf Wouf" << std::endl;
}