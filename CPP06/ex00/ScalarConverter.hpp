#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <sstream>
#include <iostream>

# define CHAR			0
# define INT			1
# define FLOAT			2
# define DOUBLE			3
# define SPECIAL		4
# define INF			5

typedef struct s_literal
{
	unsigned char	Char;
	int 			Int;
	float			Float;
	double			Double;
	std::string		Special;
	bool			isDisplayable;
}				t_literal;

class ScalarConverter {
private:
	int 			_type;
	t_literal 		_literal;
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	~ScalarConverter();

	void			convert();
	void			getLiteralType(std::string str);
	bool			isSpecialCase(std::string str);
	bool			isChar(std::string &str, std::string &digits);
	bool			isInt(std::string &str, std::string &digits);
	bool			isFloat(std::string &str, std::string &digits);
	bool			isDouble(std::string &str, std::string &digits);

	class LiteralException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Argument not of literal type char, int, float or double");
		}
	};
};

bool				is_printable(double nb);

#endif