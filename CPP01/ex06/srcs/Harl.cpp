#include "../Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug() {
	std::cout << "--- DEBUG ---" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info() {
	std::cout << "--- INFO ---" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning() {
	std::cout <<  "--- WARNING ---" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error() {
	std::cout << "--- ERROR ---" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

int	levelFilter(std::string level) {
	std::string filterlvl[] =
	{
		"default",
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 1; i < 5; i++)
	{
		if (level == filterlvl[i])
			return (i);
	}
	return (0);
}

void Harl::complain(std::string level) {

	enum lvl 
	{
		DEBUG = 1,
		INFO,
		WARNING,
		ERROR
	};

	switch(levelFilter(level)) 
	{
		
		case DEBUG :
			this->debug();
		case INFO :
			this->info();
		case WARNING :
			this->warning();
		case ERROR :
			this->error();
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	};
}