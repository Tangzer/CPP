#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <cstdlib>
#include <unistd.h>

int main()
{
//	{
//		std::cout << "--- MAIN ---" << std::endl;
//		const Animal* j = new Dog();
//		std::cout << std::endl;
//		const Animal* i = new Cat();
//		std::cout << std::endl;
//
//		delete j;//should not create a leak
//		std::cout << std::endl;
//		delete i;
//		std::cout << std::endl;
//	}
	{
		std::cout << "--- Brain deep copy ---" << std::endl;

		Dog Wouf;
		std::cout << "Wouf Brain memory address :";
		Wouf.printBrainAddress();
		std::cout << std::endl;

		Wouf.getIdea(1);
		Wouf.addIdea("This is a dog", 1);
		Wouf.getIdea(1);
		std::cout << std::endl;
		std::cout << "-------------" << std::endl;
		std::cout << std::endl;
		Dog Waf = Wouf;
		std::cout << "Waf Brain memory address :";
		Waf.printBrainAddress();
		std::cout << std::endl;
		Waf.getIdea(1);
		std::cout << std::endl;

		Cat Miaow;
		std::cout << "Miaow Brain memory address :";
		Miaow.printBrainAddress();

		Miaow.getIdea(1);
		Miaow.addIdea("This is a cat", 1);
		Cat Meow = Miaow;
		std::cout << "Meow Brain memory address :";
		Meow.printBrainAddress();
		Meow.getIdea(1);
	}
	{
		std::cout << "--- Animal array ---" << std::endl;
		Animal* tab[10];

		for (int i = 0; i < 10; i++)
		{
			std::cout << i + 1 << "/" << std::endl;
			if (i < 5)
				tab[i] = new Dog();
			else
				tab[i] = new Cat();

			std::cout << "Type: " << tab[i]->getType() << std::endl;
			tab[i]->makeSound();
			srand(time(NULL));
			int idx = rand() % 100;
			tab[i]->getIdea(idx);
			std::cout << "Brain address in memory: ";
			tab[i]->printBrainAddress();
			sleep(1);
			std::cout << std::endl;
		}
		for (int i = 9; i >= 0; i--)
		{
			std::cout << i + 1 << "/" << std::endl;
			delete tab[i];
			std::cout << std::endl;
		}
	}
	return 0;
}