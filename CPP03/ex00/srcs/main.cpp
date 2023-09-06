#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Dorian("Dorian");
	ClapTrap Tanguy("Tanguy");

	Dorian.attack("Tanguy");
	Tanguy.takeDamage(5);

	Tanguy.attack("Dorian");
	Dorian.takeDamage(7);

	Dorian.beRepaired(5);
	Tanguy.attack("Dorian");

	Dorian.takeDamage(7);
	Dorian.attack("Tanguy");

	Tanguy.takeDamage(15);
	Dorian.beRepaired(12);

	Tanguy.beRepaired(5);
	return 0;
}