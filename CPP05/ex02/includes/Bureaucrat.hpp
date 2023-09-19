#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class AForm;

class Bureaucrat {
private:
	std::string	const	_name;
	int 				_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);
	~Bureaucrat();

	std::string 	getName() const;
	int 			getGrade() const;
	void			promoteBureaucrat();
	void			demoteBureaucrat();
	void			checkGrade() const;
	void			signForm(AForm &aform);
	void			executeForm(const AForm &form);

	class GradeTooHighException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return ("Can't go above grade 1");
			}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Can't go below grade 150");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif