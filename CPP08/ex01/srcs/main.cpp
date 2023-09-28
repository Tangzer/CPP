#include <Span.hpp>

int main()
{
		srand(time(NULL));

		try {
			std::cout << "-- test 1 --" << std::endl;
			Span sp = Span(42);
			std::cout << "Max size = " << sp.getSize() << std::endl << "tab size = " << sp.tabSize() << std::endl;

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.displayTab();

			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl << std::endl;
		} catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		{
			std::cout << "-- test 2 --" << std::endl;
			Span sp = Span(10);

			sp.randomFill();
			sp.displayTab();
		}
		{
			std::cout << "-- test 3 --" << std::endl;
			Span sp = Span(10000);

			sp.randomFill();
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl << std::endl;
		}
		{
			std::cout << "-- test 4 --" << std::endl;
			Span sp = Span(1);

			sp.addNumber(6);
			try {
				std::cout << sp.shortestSpan() << std::endl;
			}
			catch (Span::NoSpanException &e) {
				std::cout << e.what() << std::endl;
			}
		}
		{
			std::cout << "-- test 5 --" << std::endl;
			Span sp = Span(1);

			sp.addNumber(6);
			try {
				std::cout << sp.longestSpan() << std::endl;
			}
			catch (Span::NoSpanException &e) {
				std::cout << e.what() << std::endl;
			}
		}
		{
			std::cout << "-- test 6 --" << std::endl;
			Span sp = Span(2);

			try {
				sp.addNumber(6);
				std::cout << "added 6" << std::endl;
				sp.addNumber(3);
				std::cout << "added 3" << std::endl;
				sp.addNumber(17);
				std::cout << "added 17" << std::endl;
				sp.addNumber(9);
				std::cout << "added 9" << std::endl;
			}
			catch (Span::AddNumberException &e) {
				std::cout << e.what() << std::endl;
			}
		}
	return 0;
}