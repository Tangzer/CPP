#include "Weapon.hpp"

//Cosntructor
Weapon::Weapon(std::string type) {
    setType(type);
}

//Deconstructor
Weapon::~Weapon() {
}

//Copy constructor
std::string const &Weapon::getType() const{
	return (this->_type);
}

//Member functions
void Weapon::setType(std::string type) {
	this->_type = type;
}