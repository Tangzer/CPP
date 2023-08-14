#include "../includes/PhoneBook.hpp"

void	handleSigint(int signum)
{
    signum = 0;
	std::cout << std::endl << "Use EXIT to quit" << std::endl;
}

int main()
{
    std::string     input;
    unsigned int    contactID = 0;

    PhoneBook       book;
    signal(SIGINT, handleSigint); // Handle ctrl + C
    while (19)
    {
        std::cout << "Do you want to ADD, SEARCH or EXIT ?" << std::endl;
        std::getline(std::cin, input);
        if (std::cin.eof() || std::cin.fail()) // Handle ctrl + D
		{
    		std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl << "Use EXIT to quit" << std::endl;
		}
        std::cin.clear();
        clearerr(stdin);
        if (input == "ADD" && contactID <= 8)
        {
            if (contactID == 8)
				contactID = 0;
			book.addContact(contactID);
			contactID++;
        }
        else if (input == "SEARCH" && contactID > 0)
            book.displayContacts();
        else if (input == "EXIT")
            exit(0);
    }
    return(0);
}