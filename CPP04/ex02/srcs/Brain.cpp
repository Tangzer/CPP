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

Brain::~Brain() {
	std::cout << "* Brain deconstructor called *" << std::endl;
}

Brain::Brain(Brain const &brain) {
	std::cout << "* Brain copy constructor called *" << std::endl;
	for (int i = 0; i < NB_OF_IDEAS; i++)
		this->_ideas[i] = brain.getIdea(i);
}

Brain &Brain::operator=(Brain const &brain) {
	std::cout << "* Brain = operator called *" << std::endl;
	for (int i = 0; i < NB_OF_IDEAS; i++)
		this->_ideas[i] = brain.getIdea(i);
	return (*this);
}

std::string	Brain::getIdea(int index) const {
	return(this->_ideas[index]);
}

void Brain::setIdea(std::string idea, int index)
{
	this->_ideas[index] = idea;
}