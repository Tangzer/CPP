#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "* MateriaSource constructor called *" << std::endl;
	for (int i = 0; i < INVSIZE; i++)
		this->_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) {
	std::cout << "* MateriaSource copy constructor called *" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < INVSIZE; i++)
			this->_storage[i] = copy._storage[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy) {
	std::cout << "* MateriaSource assignment operator called *" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < INVSIZE; i++) {
			this->_storage[i] = copy._storage[i];
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << "* MateriaSource destructor called *" << std::endl;
	for (int i = 0; i < INVSIZE; i++)
	{
		if (this->_storage[i])
			delete this->_storage[i];
	}
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0 ; i < INVSIZE; i++)
	{
		if (!_storage[i])
		{
			_storage[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource inventory full" << std::endl;
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < INVSIZE; i++)
	{
		if (type == _storage[i]->getType())
			return (_storage[i]->clone());
	}
	return (0);
}