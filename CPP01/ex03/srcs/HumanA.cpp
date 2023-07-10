#include "HumanA.hpp"

HumanA::HumanA(std::string name, const Weapon& weapon) : _weaponRef(weapon), _name(name) {

}

HumanA::~HumanA(void) {
}

void	HumanA::attack() {
	std::cout << this->_name << " attacks with " << this->_weaponRef.getType() << std::endl;
}