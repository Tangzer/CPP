#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

#define INVSIZE 4

class ICharacter;

class AMateria {
protected:
	std::string				_type;
public:
	AMateria();
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &copy);
	virtual ~AMateria();
	AMateria(std::string const &type);

	std::string const 		&getType() const; //Returns the materia type
	virtual 				AMateria* clone() const = 0;
	virtual void 			use(ICharacter &target);
};

#endif