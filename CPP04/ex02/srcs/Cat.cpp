#include "Cat.hpp"

Cat::Cat() : AAnimal() {
	std::cout << "* Cat default constructor called *" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "* Cat default deconstructor called *" << std::endl;
	delete this->_brain;
	printBrainAddress();
}

Cat::Cat(const Cat &cat) : AAnimal() {
	std::cout << "* Cat copy constructor called *" << std::endl;
	this->_brain = new Brain();
	*(this->_brain) = *(cat._brain);
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << "* Cat assignment operator called *" << std::endl;
	this->_type = cat._type;
	*(this->_brain) = *(cat._brain);
	return (*this);
}

void Cat::makeSound() const {
	std::cout << "Cat sounds..." << std::endl;
}

void Cat::printBrainAddress() {
	std::cout << &this->_brain << std::endl;
}

void Cat::getIdea(int index) const {
	std::cout << this->_brain->getIdea(index) << std::endl;
}

void Cat::setIdea(std::string idea, int index) {
	this->_brain->setIdea(idea, index);
}