#include "Ice.hpp"

Ice::Ice() :
		AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &copy) :
		AMateria(copy.getType()) {
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=(const Ice &copy) {
	if (this != &copy)
		*this = copy;
	return (*this);
}

Ice::~Ice() {
	std::cout << "Ice deconstructor called" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

AMateria* Ice::clone() const {
	AMateria* ret = new Ice();
	return (ret);
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice ball at " << target.getName() << " *" << std::endl;
}