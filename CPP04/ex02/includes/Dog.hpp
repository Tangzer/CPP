#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal {
private:
	Brain*			_brain;
public:
	Dog();
	Dog(const Dog &Dog);
	Dog &operator=(const Dog &Dog);
	virtual ~Dog();

	void virtual 	makeSound() const;

	virtual void	printBrainAddress();
	virtual void	getIdea(int index) const;
	void			setIdea(std::string idea, int index);
};

#endif