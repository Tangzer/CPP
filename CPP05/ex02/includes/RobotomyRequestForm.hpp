#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <string>
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public AForm{
private:
	std::string 	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	std::string		getTarget() const;
	void 			execute(Bureaucrat const &executor);
};

#endif