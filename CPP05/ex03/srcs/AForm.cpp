#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:	_name(""),
		_signed(false),
		_requiredGradeToSign(150),
		_requiredGradeToExecute(150) {
}

AForm::AForm(std::string const name, int const requiredGradeToSign, int const requiredGradeToExecute)
	:	_name(name),
		_signed(false),
		_requiredGradeToSign(requiredGradeToSign),
		_requiredGradeToExecute(requiredGradeToExecute) {
	checkGrade();
}

AForm::AForm(const AForm &copy)
	:	_name(copy._name),
		_requiredGradeToSign(copy.getGradeToSign()),
		_requiredGradeToExecute(copy.getGradeToExecute()) {
		*this = copy;
		checkGrade();
}

AForm::~AForm() {}

/****************************/
/* -- OVERLOAD OPERATORS -- */
/****************************/

AForm &AForm::operator=(const AForm &copy) {
	_signed = copy._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const AForm &aform) {
	std::cout << "Name: " << aform.getName() << std::endl;
	if (aform.getSignature())
		std::cout << "Signed: Yes" << std::endl;
	else
		std::cout << "Signed: No" << std::endl;
	std::cout << "Grade to sign: " << aform.getGradeToSign() << std::endl;
	std::cout << "Grade to execute: " << aform.getGradeToExecute() << std::endl;
	return (os);
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

void AForm::beSigned(Bureaucrat &bureaucrat) {
	try {
		bureaucrat.signForm(*this);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::string	AForm::getName() const {
	return (_name);
}

bool AForm::getSignature() const {
	return (_signed);
}

int	AForm::getGradeToSign() const {
	return (_requiredGradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (_requiredGradeToExecute);
}

void AForm::checkGrade() const {
	if (_requiredGradeToSign > 150 || _requiredGradeToExecute > 150) {
		throw GradeTooLowException();
	}
	if (_requiredGradeToSign < 1 || _requiredGradeToExecute < 1) {
		throw GradeTooHighException();
	}
}

void AForm::setSignature(bool signature) {
	_signed = signature;
}

void AForm::checkExecutePrivilege(const Bureaucrat &executor) const {
	if (this->getGradeToExecute() < executor.getGrade())
		throw ExecuteGradeTooLow();
	if (this->getSignature() == false)
		throw FormNotSigned();
}