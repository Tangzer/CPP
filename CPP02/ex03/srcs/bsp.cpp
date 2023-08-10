#include "Point.hpp"
//#include <cstdlib>

// Given 3 points,
// Area formula : [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2 

Fixed	getArea(Point a, Point b, Point c)
{
	Fixed aX = a.getX();
	Fixed aY = a.getY();

	Fixed bX = b.getX();
	Fixed bY = b.getY();

	Fixed cX = c.getX();
	Fixed cY = c.getY();
 
	Fixed ret = ( aX * ( bY - cY ) + bX * ( cY - aY ) + cX * ( aY - bY ) ) / 2;
	if (ret.getRawBits() < 0)
		return ( ret * -1 );
	else
		return (ret);
}

//If AREA ABC == AREA PAB + AREA PBC + AREA PAC
//THEN P IS INSIDE TRIANGLE
//IF AREA == 0, POINT IS ON LINE

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed ABC = getArea(a, b, c);
	Fixed PAB = getArea(p, a, b);
	Fixed PBC = getArea(p, b, c);
	Fixed PAC = getArea(p, a, c);

	if (PAB == 0 || PBC == 0 || PAC == 0)
		return (false);
	if (ABC == PAB + PBC + PAC)
		return (true);
	else
		return (false);
}