#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
	std::string		_type;
public:
	Animal();
	Animal(const Animal &Animal);
	Animal &operator=(const Animal &Animal);
	virtual ~Animal();

	std::string		getType() const;
	void virtual	makeSound() const;
};

#endif
