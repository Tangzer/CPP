#ifndef CAT_HPP
#define CAT_HPP

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
