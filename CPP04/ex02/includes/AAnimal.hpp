#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

//Abstact class :
//* A class is abstract if it has at least one pure virtual function.
//* The class cannot be instantiated as an object
//* It provides an appropriate base class from which other classes can inherit
//* Inheriting classes MUST implement each virtual function of the abstract class. If we do not override the pure virtual function in the derived class, then the derived class also becomes an abstract class.
//* We can have pointers and references of abstract class type.
//* An abstract class can have constructors.
//* An abstract class in C++ can also be defined using struct keyword.

class AAnimal {
protected:
	std::string		_type;

public:
	AAnimal();
	AAnimal(const AAnimal &AAnimal);
	AAnimal &operator=(const AAnimal &AAnimal);
	virtual ~AAnimal();

	void virtual	makeSound() const = 0; //pure virtual function // "= 0" --> pure specifier
	std::string		getType() const;
	virtual void 	getIdea(int index) const;
	virtual void 	printBrainAddress();
};

#endif