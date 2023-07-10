#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {						//initialize : _fixedPV to 0
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed & other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_fixedPointValue = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(const int raw) {
	_fixedPointValue = raw;
}