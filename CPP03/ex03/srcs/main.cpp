#include "DiamondTrap.hpp"

int main(void) {
	{
		std::cout << "--------------" << std::endl;
		std::cout << "--- ATTACK ---" << std::endl;
		std::cout << "--------------" << std::endl;

		DiamondTrap trap("Paulineee");
		std::cout << std::endl;
//		DiamondTrap copy = trap;
//		std::cout << std::endl;

		trap.printTrap();
		std::cout << std::endl;
//		for (int i = 0; i < 2; i++)
//			trap.attack("Jeff");
//
//		for (int i = 0; i < 2; i++)
//			copy.attack("Alfred");
	}
//	{
//		std::cout << "-------------------" << std::endl;
//		std::cout << "--- TAKE DAMAGE ---" << std::endl;
//		std::cout << "-------------------" << std::endl << std::endl;
//
//		DiamondTrap trap;
//		std::cout << std::endl;
//
//		for (int i = 0; i <= 4; i++)
//		{
//			trap.attack("Jeff");
//			trap.takeDamage(30);
//		}
//	}
//	{
//		std::cout << "--------------" << std::endl;
//		std::cout << "--- REPAIR ---" << std::endl;
//		std::cout << "--------------" << std::endl << std::endl;
//
//		DiamondTrap trap("HealBot");
//		std::cout << std::endl;
//
//		for (int i = 0; i <= 4; i++)
//		{
//			trap.takeDamage(30);
//			trap.beRepaired(5);
//		}
//	}
//	{
//		std::cout << "------------------" << std::endl;
//		std::cout << "--- Who am I ? ---" << std::endl;
//		std::cout << "-------------------" << std::endl << std::endl;
//
//		DiamondTrap trap("Jeff");
//		std::cout << std::endl;
//
//		trap.whoAmI();
//		std::cout << std::endl;
//	}
	return (0);
}