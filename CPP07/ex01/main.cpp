#include "iter.hpp"

int main() {
	int		intArray[] = {1, 2, 3, 4, 5};
	double	doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	char	charArray[] = { 'a', 'b', 'c', 'd', 'e'};

	// Using iter with intArray and printElement function
	std::cout << "Iterating over intArray: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	// Using iter with doubleArray and printElement function
	std::cout << "Iterating over doubleArray: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	// Using iter with charArray and printElement function
	std::cout << "Iterating over charArray: ";
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;
	return 0;
}