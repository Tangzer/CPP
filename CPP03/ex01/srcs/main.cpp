#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
{
	ScavTrap trap("Trappy");
	ScavTrap copy = trap;

		std::cout << std::endl;
		std::cout << "--------------" << std::endl;
		std::cout << "--- ATTACK ---" << std::endl;
		std::cout << "--------------" << std::endl << std::endl;

		for (int i = 0; i < 3; i++)
			trap.attack("Jeff");

		for (int i = 0; i < 3; i++)
			copy.attack("Alfred");
	}
	{
		std::cout << std::endl;
		std::cout << "-------------------" << std::endl;
		std::cout << "--- TAKE DAMAGE ---" << std::endl;
		std::cout << "-------------------" << std::endl;

		ScavTrap trap;
		std::cout << std::endl;

		for (int i = 0; i <= 4; i++)
		{
			std::cout << "----" << i << "----" << std::endl;
			trap.attack("Jeff");
			trap.takeDamage(30);
		}
	}
	{
		std::cout << std::endl;
		std::cout << "--------------" << std::endl;
		std::cout << "--- REPAIR ---" << std::endl;
		std::cout << "--------------" << std::endl;

		ScavTrap trap("HealBot");
		std::cout << std::endl;

		for (int i = 0; i <= 4; i++)
		{
			std::cout << "----" << i << "----" << std::endl;
			trap.takeDamage(30);
			trap.beRepaired(5);
		}
	}
	{
		std::cout << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << "--- GUARD GATE ---" << std::endl;
		std::cout << "------------------" << std::endl;

		ScavTrap trap("Jeff");
		std::cout << std::endl;

		for (int i = 0; i < 5; i++)
			trap.guardGate();
		std::cout << std::endl;

		trap.takeDamage(200);
		trap.guardGate();
	}
	return (0);
}