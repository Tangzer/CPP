#include "AMateria.hpp"

AMateria::AMateria() : _type("empty") {}

AMateria::AMateria(AMateria const &other) : _type(copy.getType()) {}

AMateria& AMateria::operator=(AMateria const &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

AMateria::AMateria(std::string const &type) : _type(type) {
}

AMateria::~AMateria() {}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

std::string const & AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter &target) {
	std::cout << "*	does nothing to " << target.getName() << " *" << std::endl;
}