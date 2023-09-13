#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public AAnimal {
private:
	Brain* 			_brain;
public:
	Cat();
	Cat(const Cat &Cat);
	Cat &operator=(const Cat &Cat);
	virtual ~Cat();

	void virtual	makeSound() const;

	virtual void	printBrainAddress();
	virtual void	getIdea(int index) const;
	void			setIdea(std::string idea, int index);
};

#endif
