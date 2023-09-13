#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
private:
	Brain*			_brain;
public:
	Dog();
	Dog(const Dog &Dog);
	Dog &operator=(const Dog &Dog);
	virtual ~Dog();

	void virtual 	makeSound() const;

	virtual void	printBrainAddress();
//	virtual void	getIdea(int index) const;
	void			addIdea(std::string idea, int index);
};

#endif