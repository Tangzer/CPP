#ifndef CODE_DOG
#define CODE_DOG

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
public:
	Dog();
	Dog(const Dog &Dog);
	Dog &operator=(const Dog &Dog);
	virtual ~Dog();

	void virtual makeSound() const;
};

#endif