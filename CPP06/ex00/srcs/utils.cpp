#include "ScalarConverter.hpp"

bool	is_printable(double nb)
{
	if (nb < 32 || nb > 126)
		return false;
	return true;
}

void	ScalarConverter::displayConversions(int precision) {
	if (_literal.isDisplayable && _type != SPECIAL)
		std::cout << _literal.Char << std::endl;
	else
		std::cout << _literal.Special << std::endl;
	if (_type != SPECIAL)
		std::cout << _literal.Int << std::endl;
	else
		std::cout << _literal.Special << std::endl;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << _literal.Float << "f" << std::endl;
	std::cout << _literal.Double << std::endl;
}

int		ScalarConverter::getPrecision(std::string str) const {
	size_t pos = 0;

	pos = str.find_first_of(".", pos);
	switch (_type)
	{
		case FLOAT:
			return (str.length() - pos - 2);
		case DOUBLE:
			return (str.length() - pos - 1);
		default:
			return (1);
	}
}