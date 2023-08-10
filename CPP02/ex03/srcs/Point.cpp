#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	//Default constructor
}

Point::Point(const float x, const float y) : _x(x), _y(y) {
	//Constructor with params
}

Point::Point(Point const &other) : _x(other._x), _y(other._y) {
	//Copy constructor
}

Point::~Point() {
}

const Fixed &Point::getX(void) const {
	return (this->_x);
}

const Fixed &Point::getY(void) const {
	return (this->_y);
}

Point &Point::operator=(Point const &other) {
    this->_x = other._x;
    this->_y = other._y;
    return (*this);
}

std::ostream&	operator<<(std::ostream& os, Point const& point) {
	Fixed x(point.getX());
	Fixed y(point.getY());
	os << "(" << (x.getRawBits() / 256) << "," << (y.getRawBits() / 256) << ")";
	return (os);
}