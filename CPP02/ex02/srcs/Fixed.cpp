#include "Fixed.hpp"

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

bool Fixed::operator>(const Fixed& rhs) const {
	return (this->_fixedPointValue > rhs._fixedPointValue);
}

bool Fixed::operator<(const Fixed& rhs) const {
	return (this->_fixedPointValue < rhs._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return (this->_fixedPointValue >= rhs._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return (this->_fixedPointValue <= rhs._fixedPointValue);
}

bool Fixed::operator==(const Fixed& rhs) const {
	return (this->_fixedPointValue == rhs._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return (this->_fixedPointValue != rhs._fixedPointValue);
}

Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;

	result._fixedPointValue = this->_fixedPointValue + rhs._fixedPointValue;
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;

	result._fixedPointValue = this->_fixedPointValue - rhs._fixedPointValue;
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed result;

	result._fixedPointValue = (this->_fixedPointValue) * (rhs._fixedPointValue) >> _fractionalBits;
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;

	result._fixedPointValue = (this->_fixedPointValue << _fractionalBits) / rhs._fixedPointValue;
	return (result);
}

//To distinguish between the two, the following rule is observed: 
//The prefix form of the operator is declared exactly the same way as any other unary operator; 
//The postfix form accepts an extra argument of type int.

Fixed& Fixed::operator++(void) //prefix
{
	this->_fixedPointValue++;
	return (*this);
}

//Example: value of var A is 1
Fixed Fixed::operator++(int) //postfix
{
	Fixed old(*this); // new var B takes current value of var A = 1
	operator++(); //operator is called on 'this' of var A, thus var A = 2 
	return (old); //return var B still = 1
}

Fixed& Fixed::operator--(void) //prefix
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--(int) //postfix
{
	Fixed old(*this);
	operator--();
	return (old);
}

/*********************************/
/*- Overloaded member functions -*/
/*********************************/

Fixed Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed	Fixed::min(Fixed const & a, Fixed const & b) {
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed Fixed::max(Fixed& a, Fixed& b) {
	if (a < b)
		return (b);
	else
		return (a);
}

const Fixed	Fixed::max(Fixed const & a, Fixed const & b) {
	if (a < b)
		return (b);
	else
		return (a);
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