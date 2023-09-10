#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

#define NB_OF_IDEAS 100

class Brain {
private:
	std::string _ideas[NB_OF_IDEAS];
public:
	Brain();
	Brain(const Brain &Brain);
	Brain &operator=(const Brain &Brain);
	~Brain();

	std::string	getIdea(int index) const;
	void		setIdea(std::string idea, int index);
};

#endif
