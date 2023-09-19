#include "Intern.hpp"

int const 			Intern::_formCount = 3;
std::string const	Intern::_formStr[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	if (this != &copy)
		*this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern detructor called." << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

 int Intern::getIndex(std::string const &name) {
	 for (int i = 0; i < _formCount; i++) {
		 if (name == _formStr[i])
			 return (i);
	 };
	 return (-1);
 }

AForm *Intern::makeForm(std::string const &form,
					   std::string const &target) const {
	int	index = getIndex(form);

	switch (index) {
		case SHRUBBERY_CREATION:
			return new ShrubberyCreationForm(target);
		case ROBOTOMY_REQUEST:
			return new RobotomyRequestForm(target);
		case PRESIDENTIAL_PARDON:
			return new PresidentialPardonForm(target);
		default:
			throw FormNotFoundException();
	}

}