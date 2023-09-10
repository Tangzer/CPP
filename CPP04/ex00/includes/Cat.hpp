#ifndef CODE_CAT
#define CODE_CAT

#include "Animal.hpp"
#include <iostream>

class Cat : public Animal {
public:
	Cat();
	Cat(const Cat &Cat);
	Cat &operator=(const Cat &Cat);
	virtual ~Cat();

	void virtual makeSound() const;
};

#endif
