#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("Shrubbery", 145, 137),
		_target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	:	AForm("Shrubbery", 145, 137),
		_target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << this->getName() << " Shrubbery deconstruction" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	:	AForm(copy.getName(), 145, 137),
		_target(copy.getTarget()) {
	this->setSignature(copy.getSignature());
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	_target = copy.getTarget();
	this->setSignature(copy.getSignature());
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) {
	checkExecutePrivilege(executor);
	std::string fileName = getTarget() + "_shrubbery.txt";
	std::ofstream	oFile(fileName);
	if ( !oFile ) {
		throw std::runtime_error( _target + "_shrubbery" + ": unable to open" );
	}
	oFile << "       _-_       " << std::endl;
	oFile << "    /~~   ~~\\    " << std::endl;
	oFile << "  /~~       ~~\\  " << std::endl;
	oFile << " {             } " << std::endl;
	oFile << " \\  _-     -_  / " << std::endl;
	oFile << "   ~  \\\\ // ~  " << std::endl;
	oFile << "  _- - | | _- _  " << std::endl;
	oFile << "    _ -| |   -_  " << std::endl;
	oFile << "      // \\\\      " << std::endl;
	std::cout << fileName << " has received a happy little ASCII tree." << std::endl;
}