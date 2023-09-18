#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade) {
	check_grade();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {
	check_grade();
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
	check_grade();
}

void Bureaucrat::demoteBureaucrat() {
	_grade++;
	check_grade();
}

void Bureaucrat::check_grade() const {
	if (_grade > 150) { throw GradeTooLowException();}
	if (_grade < 1) { throw GradeTooHighException();}
}