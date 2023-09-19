#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	Intern intern;

	try {
		AForm *form = intern.makeForm( "shrubbery creation", "target" );
		std::cout << *form << std::endl;
		delete form;
	} catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		AForm *form = intern.makeForm( "robotomy request", "target" );
		std::cout << *form << std::endl;
		delete form;
	} catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		AForm *form = intern.makeForm( "presidential pardon", "target" );
		std::cout << *form << std::endl;
		delete form;
	} catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		AForm *form = intern.makeForm( "yo", "target" );
		std::cout << *form << std::endl;
		delete form;
	} catch ( const std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}