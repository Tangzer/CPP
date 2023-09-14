#include "WrongCat.hpp"

WrongCat::WrongCat() {
	this->type = "WrongCat";
	std::cout << "* WrongCat default constructor called *" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat) {
	if (this != &WrongCat)
		*this = WrongCat;
	std::cout << "* WrongCat copy constructor called *" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat) {
	std::cout << "* WrongCat assignment operator called *" << std::endl;
	this->type = WrongCat.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << "* WrongCat default deconstructor called *" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void	WrongCat::makeSound() const {
	std::cout << "Wrong Cat sounds..." << std::endl;
}