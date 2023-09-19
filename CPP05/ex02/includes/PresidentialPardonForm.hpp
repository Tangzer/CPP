#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include <string>

class PresidentialPardonForm : public AForm{
private:
	std::string 	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	std::string		getTarget() const;
	void			execute(const Bureaucrat &executor) const;
};

#endif