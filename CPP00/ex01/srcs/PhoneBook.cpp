#include "../includes/PhoneBook.hpp"

std::string truncateInfo(std::string info)
{
	int	spaceNb = 10 - info.length();
	if (spaceNb > 0 && info.length() < 9)
	{
		if (info.length() % 2 == 0)
			info = info.insert(0, spaceNb / 2, ' ');
		else
			info = info.insert(0, (spaceNb / 2) + 1, ' ');
		info = info.insert(info.length(), spaceNb / 2, ' ');
	}
	if (info.length() <= 10)
		return (info);
	else
	{
		info = info.substr(0, 9) + ".";
		return (info);
	}
}

void	PhoneBook::addContact(int contactID) {
	_contacts[contactID].setID(contactID);
	_contacts[contactID].setFirstName();
	_contacts[contactID].setLastName();
	_contacts[contactID].setNickname();
	_contacts[contactID].setPhoneNr();
	_contacts[contactID].setDarkestSecret();
}

void	PhoneBook::searchContactById() {
	int			contactID;
	std::string	temp;

	if (this->_contacts[0].getFirstName().empty())
		std::cout << "Contact list is empty. Try adding a contact first." << std::endl;
	while (1)
	{
		std::cout << "What's the contact ID you're searching?" << std::endl;
		std::getline(std::cin, temp);
		if (std::cin.eof() || std::cin.fail())
		{
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl << "Use EXIT to quit" << std::endl;
		}
		if (temp == "EXIT")
		{
			std::cout << "Exit program." << std::endl;
			exit(0);
		}
		if (temp.empty())
			continue ;
		try
		{
			contactID = std::stoi(temp);
		}
		catch (const std::out_of_range)
		{
			std::cout << "Invalid type. Please try again." << std::endl;
		}
		if (contactID < 8 && contactID >= 0)
			_contacts[contactID].getInfo(contactID);
		else
			std::cout << "Index should be between 0 and 7" << std::endl;
	}
}

void	PhoneBook::displayContacts() {
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	int			i;
	int			contactID;

	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|  Index   |Firstname | Lastname | Nickname |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	i = 0;
	while (i < 8)
	{
		firstname = _contacts[i].getFirstName();
		lastname = _contacts[i].getLastName();
		nickname = _contacts[i].getNickName();
		contactID = _contacts[i].getID();
		if (!firstname.empty())
		{
			firstname = truncateInfo(firstname);
			lastname = truncateInfo(lastname);
			nickname = truncateInfo(nickname);
			std::cout << "|    " << contactID
				<< "     |" << firstname << "|"
				<< lastname << "|" << nickname << "|" << std::endl;
			std::cout << "+----------+----------+----------+----------+" << std::endl;
		}
		i++;
	}
	searchContactById();
	return ;
}