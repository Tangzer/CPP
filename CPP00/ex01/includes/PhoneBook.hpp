#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{
private:
	Contact _contacts[8];
public:
	void	addContact(int contactID);
	void	displayContacts();
	void	searchContactById();
};