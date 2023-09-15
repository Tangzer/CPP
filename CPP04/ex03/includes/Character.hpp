#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

#define INVSIZE 4
#define GROUNDSIZE 10

class Character : public ICharacter {
private:
	std::string 				_name;
	AMateria*					_storage[INVSIZE];
	AMateria*					_mUnequiped[GROUNDSIZE];
public:
	Character();
	Character(std::string const name);
	Character(const Character &copy);
	Character &operator=(const Character &copy);
	~Character();

	virtual const std::string 	&getName() const;
	virtual void 				equip(AMateria *m);
	virtual void 				unequip(int idx);
	virtual void 				use(int idx, ICharacter &target);
	bool 						addToList(AMateria *storage[], int idx);
	void						getStorageMemoryAddress(void);
};

#endif