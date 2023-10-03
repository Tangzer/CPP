int	main(int ac, char **av) {
	RPN	rpn;

	if (ac != 2) {
		std::cerr << "Error: wrong number of arguments\n";
		return (1);
	}
	if (std::strlen(argv[1]) <= 0) {
		std::cerr << "Error: empty string\n";
		return (1);
	}

	return (0);
}