#include "AAnimal.hpp"

AAnimal::AAnimal() {
	this->_type = "AAnimal";
	std::cout << "* AAnimal default constructor called *" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "* AAnimal default deconstructor called *" << std::endl;
}

AAnimal::AAnimal(const AAnimal &aanimal) {
	*this = aanimal;
	std::cout << "* AAnimal copy constructor called *" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &aanimal) {
	std::cout << "* AAnimal assignment operator called *" << std::endl;
	this->_type = aanimal._type;
	return (*this);
}

void AAnimal::makeSound() const {
	std::cout << "AAnimal sounds..." << std::endl;
}

std::string	AAnimal::getType() const {
	return (this->_type);
}

void AAnimal::getIdea(int index) const {
	(void)index;
}

void AAnimal::printBrainAddress() {
	std::cout << "AAnimals don't have brains..." << std::endl;
}