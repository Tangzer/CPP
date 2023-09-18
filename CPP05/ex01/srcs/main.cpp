#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Form f( "F1", 30, -1 );
	} catch ( std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	try {
		Form f( "F2", 1, 160 );
	} catch ( std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat1 = Bureaucrat( "bureaucrat1", 1 );
		std::cout << bureaucrat1 << std::endl;
		Form f( "F3", 150, 150 );
		std::cout << f << std::endl;
		bureaucrat1.signForm( f );
		std::cout << f << std::endl;
	} catch ( std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat bureaucrat2 = Bureaucrat( "bureaucrat2", 30 );
		std::cout << bureaucrat2 << std::endl;
		Form f( "F4", 29, 150 );
		std::cout << f << std::endl;
		bureaucrat2.signForm( f );
		std::cout << f << std::endl;
	} catch ( std::exception &e ) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}