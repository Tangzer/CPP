#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

    Fixed(const int intNumber);
    Fixed(const float floatNumber);

	int			getRawBits(void) const;
	void		setRawBits(int const raw);

	float	toFloat(void) const;
	int 	toInt(void) const;
};

int	myPow(int base, int power);
std::ostream& operator<<(std::ostream& os, Fixed const & fixed);

#endif