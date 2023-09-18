#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat b( "b", 151 );
		std::cout << b << std::endl;
		b.promoteBureaucrat();
		std::cout << b << std::endl;
		b.demoteBureaucrat();
		std::cout << b << std::endl;
		b.demoteBureaucrat();
		std::cout << b << std::endl;
	} catch ( std::exception const &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}