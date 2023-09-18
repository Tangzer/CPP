#include <new>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>


//Interface :
//specify a contract that parts of the program have to conform to
//Unlike abstract class which can, methods have no body for interface
//Serves as a guideline, the way the code is supposed to be used/implemented

int main()
{
	{
		std::cout << "------- PDF MAIN -------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		std::cout << std::endl;

		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << "------- UNEQUIPED MATERIA -------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		ICharacter* jason = new Character("Jason");
		AMateria* tmp;
		std::cout << std::endl;
		for (int i = 0; i < 11; i++)
		{
			tmp = src->createMateria("ice");
			jason->equip(tmp);
			jason->unequip(0);
		}
		std::cout << std::endl;
		delete jason;
		delete src;
	}
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		Character* alfred = new Character("Alfred");
		AMateria* tmp;
		std::cout << std::endl;
		for (int i = 0; i < 5; i++)
		{
			tmp = src->createMateria("ice");
			alfred->equip(tmp);
		}
		std::cout << std::endl;
		Character bob = *alfred;
		std::cout << std::endl;
		std::cout << "Alfred storage: " << std::endl;
		alfred->getStorageMemoryAddress();
		std::cout << std::endl;
		bob.use(1, bob);
		std::cout << std::endl;
		delete alfred;
		std::cout << std::endl;
		std::cout << "Bob storage: " << std::endl;
		bob.getStorageMemoryAddress();
		std::cout << std::endl;
		bob.use(1, bob);
		std::cout << std::endl;

		delete src;
		std::cout << std::endl;

	}
	{
		std::cout << std::endl << "------- DEEP COPY ASSIGNMENT OPERATOR -------" << std::endl;
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character alfred = Character("Alfred");
		AMateria* tmp;
		for (int i = 0; i < 2; i++)
		{
			tmp = src->createMateria("ice");
			alfred.equip(tmp);
		}

		Character bob = Character("Bob");
		for (int i = 0; i < 4; i++)
		{
			tmp = src->createMateria("cure");
			bob.equip(tmp);
		}
		bob = alfred;
		std::cout << "Alfred storage: " << std::endl;
		alfred.getStorageMemoryAddress();
		bob.use(1, bob);
		std::cout << "Bob storage: " << std::endl;
		bob.getStorageMemoryAddress();
		bob.use(1, bob);

		delete src;
	}
	return 0;
}