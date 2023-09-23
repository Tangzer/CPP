#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		std::string convStr = av[1];
		ScalarConverter	scalar;

//		try
//		{
//			scalar.getLiteralType(convStr);
//			scalar.convert();
//			scalar.displayConversions(scalar.getPrecision(convStr));
//		}
//		catch (std::exception& e)
//		{
//			std::cout << e.what() << std::endl;
//		}
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
	return (0);
}