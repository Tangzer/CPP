#include "Fixed.hpp"

/***********************/
/* --- CONSTRUCTORS ---*/
/***********************/
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intNumber) {
     std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = intNumber << this->_fractionalBits;
}

Fixed::Fixed(const float floatNumber) {
    std::cout << "Float constructor called" <<  std::endl;
    int power = myPow(2, this->_fractionalBits);
    this->_fixedPointValue = roundf(floatNumber * power);
}

/***************************/
/* --- COPY CONSTRUCTOR ---*/
/***************************/

Fixed::Fixed(const Fixed & copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

/****************************/
/* --- OPERATOR OVERLOAD ---*/
/****************************/

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Fixed const & fixed) {
    os << fixed.toFloat() << std::endl;
    return (os);
}

/************************/
/* --- DECONSTRUCTOR ---*/
/************************/

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/****************************/
/* --- MEMBER FUNCTIONS --- */
/****************************/

int Fixed::getRawBits() const {
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(const int raw) {
	_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    float power = myPow(2, this->_fractionalBits);
    return ((this->_fixedPointValue / power));
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> this->_fractionalBits);
}

/****************************/
/*      --- OTHERS ---      */
/****************************/

int	myPow(int base, int power)
{
	int ret = 1;

	for (int i = 0; i < power; i++)
		ret *= base;
	return (ret);
}