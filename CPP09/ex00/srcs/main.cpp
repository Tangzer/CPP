#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return (1);
	}
	try {
		BitcoinExchange btc;
		btc.applyExchange(av[1]);
	} catch (std::ios_base::failure &e) {
		std::cerr << "I/O Error: " << e.what() << std::endl;
	} catch (const std::runtime_error &e) {
		std::cerr << "Runtime error: " << e.what() << std::endl;
	}
	return (0);
}