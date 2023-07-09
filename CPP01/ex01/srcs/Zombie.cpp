#include "./Zombie.hpp"

Zombie::Zombie() {
}

Zombie::~Zombie() {
	std::cout << _name << "'s Destructor called" << std::endl;
}

void Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string zombieName) {
	_name = zombieName;
}