#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
    Fixed(const int intNumber);
    Fixed(const float floatNumber);
    Fixed& operator=(const Fixed & other);

    bool operator<(const Fixed &rhs) const;
	bool operator>(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;

	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;

    Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

    static Fixed		min(Fixed& a, Fixed& b);
	static const Fixed	min(Fixed const & a, Fixed const & b);
	static Fixed		max(Fixed& a, Fixed& b);
	static const Fixed	max(Fixed const & a, Fixed const & b);

    ~Fixed();

	int			getRawBits(void) const;
	void		setRawBits(int const raw);
	float	    toFloat(void) const;
	int 	    toInt(void) const;
};

int	myPow(int base, int power);
std::ostream& operator<<(std::ostream& os, Fixed const & fixed);

#endif