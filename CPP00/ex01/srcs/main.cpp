#include "../includes/PhoneBook.hpp"

int main()
{
    std::string     input;
    unsigned int    contactID = 0;

    PhoneBook       book;
    while (19)
    {
        std::cout << "Do you want to ADD, SEARCH or EXIT ?" << std::endl;
        std::getline(std::cin, input);
        system("clear");
        std::cin.clear();
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