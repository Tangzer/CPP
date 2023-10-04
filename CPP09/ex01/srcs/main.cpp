#include "RPN.hpp"

int	RPN::printError(const std::string str) {
	std::cerr << "Error: " << str << std::endl;
	return (1);
}

static int	printError(const std::string str) {
	std::cerr << "Error: " << str << std::endl;
	return (1);
}

int	main(int ac, char **av) {
	if (ac != 2)
		return (printError("wrong number of arguments."));
	if (std::strlen(av[1]) <= 0)
		return (printError("empty string."));
	RPN	rpn(av[1]);
	if (rpn.getArgStatus() == false)
		return (printError("bad input."));
	rpn.reversePolishNotation();
	return (0);
}