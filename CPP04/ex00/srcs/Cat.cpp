#include "Cat.hpp"

Cat::Cat() {
	this->_type = "Cat";
	std::cout << "* Cat default constructor called *" << std::endl;
}

Cat::~Cat() {
	std::cout << "* Cat default deconstructor called *" << std::endl;
}

Cat::Cat(const Cat &cat) {
	*this = cat;
	std::cout << "* Cat copy constructor called *" << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "* Cat assignment operator called *" << std::endl;
	this->_type = cat._type;
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Cat sounds..." << std::endl;
}