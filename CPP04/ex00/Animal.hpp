#ifndef CPP_ANIMAL
#define CPP_ANIMAL

class Animal {
protected:
	std::string	_type;

public:
	Animal();
	Animal(const Animal &Animal);
	Animal &operator=(const Animal &Animal);
	~Animal();

	std::string	getType();
	void		makeSound();
};

#endif
