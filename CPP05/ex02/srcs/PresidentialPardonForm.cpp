#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	:	AForm("Pardon", 25, 5),
		_target("") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	:	AForm("Pardon", 25, 5),
		_target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	:	AForm (copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()),
		_target(copy.getTarget()) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	_target = copy.getTarget();
	setSignature(copy.getSignature());
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const {
	return (_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) {
	this->checkExecutePrivilege(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}