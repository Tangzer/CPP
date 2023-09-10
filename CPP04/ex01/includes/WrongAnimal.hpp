#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <string>
# include <iostream>

class WrongAnimal {
protected:
	std::string	type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal &WrongAnimal);
	WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
	virtual ~WrongAnimal();

	void		makeSound() const;
	std::string	getType() const;
};

#endif
