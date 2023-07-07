#include <iostream>
#include <string>

class Contact
{
private:
	unsigned int	_contactID;
	std::string		_firstName;
	std::string		_lastName;
	std::string		_nickname;
	std::string		_phoneNumber;
	std::string		_darkestSecret;
public:
	void			setID(unsigned int contactIdToSet);
	void 			setFirstName();
	void			setLastName();
	void			setNickname();
	void			setPhoneNr();
	void			setDarkestSecret();

	void			getInfo(unsigned int contactID);
	unsigned int	getID();
	std::string 	getFirstName();
	std::string 	getLastName();
	std::string		getNickName();
};