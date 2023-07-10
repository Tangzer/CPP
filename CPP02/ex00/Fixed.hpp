#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
    ~Fixed();
	Fixed(const Fixed & other);                 //Copy constructor
	Fixed & operator=(const Fixed & other);    //Overload ssignment operator. It is used to assign the value of one object to another

	int			getRawBits() const;
	void		setRawBits(int const raw);
};

#endif