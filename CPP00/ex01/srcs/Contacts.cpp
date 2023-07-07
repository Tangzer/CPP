#include "../includes/Contact.hpp"

void Contact::setID(unsigned int contactIdToSet) {
	this->_contactID = contactIdToSet;
}

void Contact::setFirstName() {
	std::string name_to_set;

	while (name_to_set.empty())
	{
		std::cout << "Enter first name : " << std::endl;
		std::getline(std::cin, name_to_set);
		system("clear");
		std::cin.clear();
		if (name_to_set.empty())
			std::cout << "Name is empty" << std::endl;
	}
	this->_firstName = name_to_set;
}

void Contact::setLastName() {
	std::string name_to_set;

	while (name_to_set.empty())
	{
		std::cout << "Enter last name : " << std::endl;
		std::getline(std::cin, name_to_set);
		system("clear");
		std::cin.clear();
		if (name_to_set.empty())
			std::cout << "Name is empty" << std::endl;
	}
	this->_lastName = name_to_set;
}

void	Contact::setNickname() {
	std::string nickname_to_set;

	while (nickname_to_set.empty())
	{
		std::cout << "Enter Nickname : " << std::endl;
		std::getline(std::cin, nickname_to_set);
		system("clear");
		std::cin.clear();
		if (nickname_to_set.empty())
			std::cout << "Nickname is empty" << std::endl;
	}
	this->_nickname = nickname_to_set;
}

void Contact::setPhoneNr() {
	std::string phone_to_set;

	while (phone_to_set.empty())
	{
		std::cout << "Enter Phone Nr : " << std::endl;
		std::getline(std::cin, phone_to_set);
		system("clear");
		std::cin.clear();
		if (phone_to_set.empty())
			std::cout << "Phone is empty" << std::endl;
	}
	this->_phoneNumber = phone_to_set;
}

void Contact::setDarkestSecret() {
	std::string secret_to_set;
	while (secret_to_set.empty())
	{
		std::cout << "Darkest Secret : " << std::endl;
		std::getline(std::cin, secret_to_set);
		system("clear");
		std::cin.clear();
		if (secret_to_set.empty())
			std::cout << "Secret field is empty" << std::endl;
	}
	this->_darkestSecret = secret_to_set;
}

void Contact::getInfo(unsigned int contactId) {
    if (this->_firstName.empty())
		return;
    else
	{
		std::cout << "Id " << contactId << "'s First Name : " << this->_firstName << std::endl;
		std::cout << "Id " << contactId << "'s Last Name : " << this->_lastName << std::endl;
		std::cout << "Id " << contactId << "'s Nickname : " << this->_nickname << std::endl;
		std::cout << "Id " << contactId << "'s Phone Number : " << this->_phoneNumber << std::endl;
		std::cout << "Id " << contactId << "'s Darksest Secret : " << this->_darkestSecret << std::endl;
	}
}

unsigned int Contact::getID() {
	return (_contactID);
}

std::string Contact::getFirstName() {
	return (_firstName);
}

std::string Contact::getLastName() {
	return (_lastName);
}

std::string Contact::getNickName() {
	return (_nickname);
}