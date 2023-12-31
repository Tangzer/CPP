#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	checkGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	*this = copy;
	checkGrade();
}

Bureaucrat::~Bureaucrat() {}

/****************************/
/* -- OVERLOAD OPERATORS -- */
/****************************/

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
	this->_grade = copy.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &copy) {
	std::cout << copy.getName() << ", bureaucrat grade " << copy.getGrade() << "." << std::endl;
	return (os);
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::promoteBureaucrat() {
	_grade--;
	checkGrade();
}

void Bureaucrat::demoteBureaucrat() {
	_grade++;
	checkGrade();
}

void Bureaucrat::checkGrade() const {
	if (_grade > 150) { throw GradeTooLowException();}
	if (_grade < 1) { throw GradeTooHighException();}
}

void Bureaucrat::signForm(AForm &aform) {
	try
	{
		if (this->getGrade() > aform.getGradeToSign())
		{
			std::cout << getName() << " couldn't sign " << aform.getName() << " because ";
			throw AForm::GradeTooLowException();
		}
		else
		{
			std::cout << getName() << " signed " << aform.getName() << std::endl;
			aform.setSignature(true);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &aform) {
	try {
		aform.execute(*this);
		std::cout << _name << " executed form: " << aform.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}