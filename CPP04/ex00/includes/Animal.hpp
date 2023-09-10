#ifndef CPP_ANIMAL
#define CPP_ANIMAL

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
