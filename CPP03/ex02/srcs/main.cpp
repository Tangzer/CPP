#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
	{
		std::cout << "--------------" << std::endl;
		std::cout << "--- ATTACK ---" << std::endl;
		std::cout << "--------------" << std::endl << std::endl;

		FragTrap trap("Trappy");
		FragTrap copy = trap;
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
			trap.attack("Jeff");

		for (int i = 0; i < 3; i++)
			copy.attack("Alfred");
	}
	{
		std::cout << "-------------------" << std::endl;
		std::cout << "--- TAKE DAMAGE ---" << std::endl;
		std::cout << "-------------------" << std::endl;

		FragTrap trap;
		std::cout << std::endl;

		for (int i = 0; i <= 4; i++)
		{
			std::cout << "----" << i << "----" << std::endl;
			trap.attack("Jeff");
			trap.takeDamage(30);
		}
	}
	{
		std::cout << "--------------" << std::endl;
		std::cout << "--- REPAIR ---" << std::endl;
		std::cout << "--------------" << std::endl;

		FragTrap trap("HealBot");
		std::cout << std::endl;

		for (int i = 0; i <= 4; i++)
		{
			std::cout << "----" << i << "----" << std::endl;
			trap.takeDamage(30);
			trap.beRepaired(5);
		}
	}
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "--- HIGH FIVE ---" << std::endl;
		std::cout << "-----------------" << std::endl;

		FragTrap trap("Jeff");
		std::cout << std::endl;

		trap.highFivesGuys();
		std::cout << std::endl;
	}
	return (0);
}