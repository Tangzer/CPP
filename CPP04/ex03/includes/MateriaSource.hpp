#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include <string>

class MateriaSource : public IMateriaSource {
private:
	AMateria*	_storage[INVSIZE];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &copy);
	~MateriaSource();

	virtual void 		learnMateria(AMateria*);
	virtual AMateria* 	createMateria(std::string const &type);
};

#endif