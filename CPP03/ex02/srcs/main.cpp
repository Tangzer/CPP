#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	{
		std::cout << "--------------" << std::endl;
		std::cout << "--- ATTACK ---" << std::endl;
		std::cout << "--------------" << std::endl << std::endl;

		FragTrap trap("Trappy");
		FragTrap copy;

		for (int i = 0; i < 3; i++)
			trap.attack("Jeff");

		copy = trap;
		for (int i = 0; i < 3; i++)
			copy.attack("Alfred");
	}
	{
		std::cout << "-------------------" << std::endl;
		std::cout << "--- TAKE DAMAGE ---" << std::endl;
		std::cout << "-------------------" << std::endl;

		FragTrap trap;

		for (int i = 0; i <= 4; i++)
		{
			trap.attack("Jeff");
			trap.takeDamage(30);
		}
	}
	{
		std::cout << "--------------" << std::endl;
		std::cout << "--- REPAIR ---" << std::endl;
		std::cout << "--------------" << std::endl;

		FragTrap trap("HealBot");

		for (int i = 0; i <= 4; i++)
		{
			trap.takeDamage(30);
			trap.beRepaired(5);
		}
	}
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "--- HIGH FIVE ---" << std::endl;
		std::cout << "-----------------" << std::endl;

		FragTrap trap("Jeff");
		trap.highFivesGuys();
	}
	return (0);
}