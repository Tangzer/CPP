#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:	_name(""),
		_signed(false),
		_requiredGradeToSign(150),
		_requiredGradeToExecute(150) {
}

Form::Form(std::string const name, int const requiredGradeToSign, int const requiredGradeToExecute)
	:	_name(name),
		_signed(false),
		_requiredGradeToSign(requiredGradeToSign),
		_requiredGradeToExecute(requiredGradeToExecute) {
	checkGrade();
}

Form::Form(const Form &copy)
	:	_name(copy._name),
		_requiredGradeToSign(copy.getGradeToSign()),
		_requiredGradeToExecute(copy.getGradeToExecute()) {
		*this = copy;
		checkGrade();
}

Form::~Form() {}

/****************************/
/* -- OVERLOAD OPERATORS -- */
/****************************/

Form &Form::operator=(const Form &copy) {
	_signed = copy._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
	std::cout << "Name: " << form.getName() << std::endl;
	if (form.getSignature())
		std::cout << "Signed: Yes" << std::endl;
	else
		std::cout << "Signed: No" << std::endl;
	std::cout << "Grade to sign: " << form.getGradeToSign() << std::endl;
	std::cout << "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return (os);
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void Form::beSigned(Bureaucrat &bureaucrat) {
	try {
		bureaucrat.signForm(*this);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::string	Form::getName() const {
	return (_name);
}

bool Form::getSignature() const {
	return (_signed);
}

int	Form::getGradeToSign() const {
	return (_requiredGradeToSign);
}

int	Form::getGradeToExecute() const {
	return (_requiredGradeToExecute);
}

void Form::checkGrade() const {
	if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150) {
		throw GradeTooLowException();
	}
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1) {
		throw GradeTooHighException();
	}
}

void Form::setSignature(bool signature) {
	_signed = signature;
}