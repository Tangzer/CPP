#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:	AForm("Robotomy", 72, 45),
		_target("") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:	AForm("Robotomy", 72, 45),
		_target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	:	AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExecute()),
		_target(copy.getTarget()) {
	setSignature(copy.getSignature());
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	_target = copy.getTarget();
	setSignature(copy.getSignature());
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const {
	return (_target);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) {
	this->checkExecutePrivilege(executor);
	srand(time(NULL));
	int nb = rand() % 2;
	std::cout << "nb : " << nb << std::endl;
	std::cout << "Drilling noises..." << std::endl;
	if (nb)
		std::cout << this->getTarget() << " has been robotomized !" << std::endl;
	else
		std::cout << this->getTarget() << "'s robotomy failed ..." << std::endl;
}