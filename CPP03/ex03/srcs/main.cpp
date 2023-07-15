#include "DiamondTrap.hpp"

int main(void) {
	{
		std::cout << "--------------" << std::endl;
		std::cout << "--- ATTACK ---" << std::endl;
		std::cout << "--------------" << std::endl << std::endl;

		DiamondTrap trap("Trappy");
		DiamondTrap copy;

		std::cout << std::endl;
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

		DiamondTrap trap;

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

		DiamondTrap trap("HealBot");

		for (int i = 0; i <= 4; i++)
		{
			trap.takeDamage(30);
			trap.beRepaired(5);
		}
	}
	{
		std::cout << "------------------" << std::endl;
		std::cout << "--- Who am I ? ---" << std::endl;
		std::cout << "-------------------" << std::endl;

		DiamondTrap trap("Jeff");
		trap.whoAmI();
	}
	return (0);
}