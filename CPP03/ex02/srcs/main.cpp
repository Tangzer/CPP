#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap claptrap1("Clappy");
	ClapTrap claptrap2("Trappy");
	ScavTrap scavtrap1("Scavvy");
	ScavTrap scavtrap2("Guardy");

	// ClapTrap attacking
	claptrap1.attack("Trappy");
	claptrap2.attack("Clappy");

	// ScavTrap attacking
	scavtrap1.attack("Clappy");
	scavtrap2.attack("Scavvy");

	// ClapTrap taking damage and repairing
	claptrap1.takeDamage(5);
	claptrap1.beRepaired(3);

	// ScavTrap taking damage and repairing
	scavtrap1.takeDamage(15);
	scavtrap1.beRepaired(10);

	// ScavTrap using its special ability
	scavtrap1.guardGate();
	scavtrap2.guardGate();

	// ClapTrap and ScavTrap interacting
	claptrap1.attack("Scavvy");
	scavtrap1.takeDamage(5);

	scavtrap2.attack("Trappy");
	claptrap2.takeDamage(20);

	return 0;
}