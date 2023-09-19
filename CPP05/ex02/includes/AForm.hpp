#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <ostream>

class Bureaucrat;

class AForm {
private:
	std::string const	_name;
	bool				_signed;
	int const			_requiredGradeToSign;
	int const			_requiredGradeToExecute;
public:
	AForm();
	AForm(std::string const name, int const requiredGradeToSign, int const requiredGradeToExecute);
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);
	virtual ~AForm();

	void				beSigned(Bureaucrat &bureaucrat);
	std::string			getName() const;
	bool				getSignature() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;
	void				checkGrade() const;
	void				setSignature(bool sign);

	void				checkExecutePrivilege(const Bureaucrat &executor) const;
	virtual void		execute(const Bureaucrat &executor) const = 0;	//pure virtual class --> no implementation in the base class, must be overridden by any concrete (non-abstract) derived class

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
	class ExecuteGradeTooLow : public std::exception
	{
	public:
		virtual const char* what() const throw() {
			return ("Grade too low to execute");
		}
	};
	class FormNotSigned : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Form needs to be signed to execute");
		}
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &aform);

#endif