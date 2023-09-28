#include "easyfind.hpp"

struct F {
	int operator()() { return rand() % 10; }
};

int main() {
	int const			x  = 3;
	std::list<int>		v( 10 );

	srand(time(0));
	std::generate(v.begin(), v.end(), F());
	std::cout << v << std::endl;

	try {
		std::list<int>::iterator it = easyfind(v, x);
		if (it != v.end())
			std::cout << x << " was found at index " << std::distance(v.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << x << " was not found" << std::endl;
	}
	return 0;
}