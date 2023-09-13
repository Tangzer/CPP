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

void Brain::addIdea(std::string idea, int index)
{
	this->_ideas[index] = idea;
}