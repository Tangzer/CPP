#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("Clappy");
	ClapTrap clapTrap2("Trappy");

	claptrap1.attack("Trappy");
	clapTrap2.takeDamage(5);

	clapTrap2.attack("20");
	claptrap1.takeDamage(7);

	claptrap1.beRepaired(5);
	clapTrap2.attack("Clappy");

	claptrap1.takeDamage(7);
	claptrap1.attack("Trappy");

	clapTrap2.takeDamage(15);
	claptrap1.beRepaired(12);

	clapTrap2.beRepaired(5);
	return 0;
}