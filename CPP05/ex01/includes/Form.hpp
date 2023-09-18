#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class Form {
private:
	std::string const	_name;
	bool				_signed;
	int const			_requiredGradeToSign;
	int const			_requiredGradeToExecute;
public:
	Form();
	Form(std::string const name, int const requiredGradeToSign, int const requiredGradeToExecute);
	Form(const Form &copy);
	Form &operator=(const Form &copy);
	~Form();

	void				beSigned(Bureaucrat &bureaucrat);
	std::string			getName() const;
	bool				getSignature() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				checkGrade() const;
	void				setSignature(bool sign);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Grade is too high!");
		}
	};
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw() {
			return ("Grade is too low!");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif