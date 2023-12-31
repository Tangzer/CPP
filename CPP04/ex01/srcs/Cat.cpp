#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "* Cat default constructor called *" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal() {
	std::cout << "* Cat copy constructor called *" << std::endl;
	if (this != &other)
		*this = other;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "* Cat assignment operator called *" << std::endl;
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	return (*this);
}

Cat::~Cat() {
	std::cout << "* Cat default deconstructor called *" << std::endl;
	delete(this->_brain);
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void Cat::makeSound() const {
	std::cout << "Meooow..." << std::endl;
}

void Cat::printBrainAddress() {
	std::cout << &this->_brain << std::endl;
}

void Cat::addIdea(std::string idea, int index) {
	index = 0;
	this->_brain->addIdea(idea, index);
}

void Cat::getIdea(int index) const
{
	std::cout << this->_brain->getIdea(index) << std::endl;
}