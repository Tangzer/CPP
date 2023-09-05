#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point {
private :
    Fixed const _x;
    Fixed const _y;
public :
    Point();
    Point(const float x, const float y);
    Point(Point const &other);
    Point &operator=(Point const &other);
    ~Point();

    const Fixed &getX() const;
	const Fixed &getY() const;
};

std::ostream&	operator<<(std::ostream& os, Point const& point);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif