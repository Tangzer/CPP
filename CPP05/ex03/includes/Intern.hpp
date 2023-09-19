#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <string>
#include <iostream>

class Intern {
private:
	static int const         _formCount;
	static std::string const _formStr[];

	enum _formType {
		SHRUBBERY_CREATION,
		ROBOTOMY_REQUEST,
		PRESIDENTIAL_PARDON
	};

	static int 				getIndex( std::string const &name );
public:
	Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
	~Intern();

	AForm					*makeForm(std::string const &form, std::string const &target) const;

	class FormNotFoundException : public std::exception {
		virtual const char *what() const throw() {
			return "form not found.";
		};
	};
};

#endif