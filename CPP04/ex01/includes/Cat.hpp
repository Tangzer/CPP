#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public Animal {
private:
	Brain* 			_brain;
public:
	Cat();
	Cat(const Cat &Cat);
	Cat &operator=(const Cat &Cat);
	virtual ~Cat();

	void virtual	makeSound() const;

	virtual void	printBrainAddress();
//	virtual void	getIdea(int index) const;
	void			addIdea(std::string idea, int index);
};

#endif
