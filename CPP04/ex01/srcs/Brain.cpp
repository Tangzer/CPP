# include "Brain.hpp"

std::string IntToString(int nb) {
	std::ostringstream temp;
	temp << nb;
	return temp.str();
}

Brain::Brain() {
	std::cout << "* Brain default constructor called *" << std::endl;
	for (int i = 0; i < NB_OF_IDEAS; i++)
		this->_ideas[i] = "Idea nb " + IntToString(i + 1);
}

Brain::Brain(Brain const &other) {
	std::cout << "* Brain copy constructor called *" << std::endl;
	if (this != &other)
		*this = other;
}

Brain &Brain::operator=(Brain const &other) {
	std::cout << "* Brain Coopy assignment operator called *" << std::endl;
	for (int i = 0; i < NB_OF_IDEAS; i++)
		this->_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "* Brain deconstructor called *" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void Brain::addIdea(std::string idea, int index) {
	if (index > 0 && index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << "index must be between 0 and 99" << std::endl;
}

std::string Brain::getIdea(int index) const {
	return (this->_ideas[index]);
}