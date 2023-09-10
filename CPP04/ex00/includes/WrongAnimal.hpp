#ifndef CODE_WRONGANIMAL
#define CODE_WRONGANIMAL

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
