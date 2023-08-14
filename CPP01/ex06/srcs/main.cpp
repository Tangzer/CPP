#include "Harl.hpp"

int	main(int ac, char **av) {
	if (ac != 2)
	{
		std::cout << "The program has to be run with one parameter, no more, no less." << std::endl;
		return (0);
	}
	Harl Karen;
	Karen.complain(av[1]);
	return (0);
}