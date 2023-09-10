#ifndef CODE_WRONGCAT
#define CODE_WRONGCAT

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat: public WrongAnimal {
public:
	WrongCat();
	WrongCat(const WrongCat &WrongCat);
	WrongCat &operator=(const WrongCat &WrongCat);
	virtual ~WrongCat();

	void	makeSound() const;
};

#endif
