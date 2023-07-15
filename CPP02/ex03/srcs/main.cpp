#include "Fixed.hpp"
#include "Point.hpp"

// Use for visual aid while testing
// https://www.geogebra.org/graphing

int main(void) 
{
	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);

	Point p1(5, 0);
	Point p2(1, 3);
	Point p3(0, 2);
	Point p4(4, 1);
	Point p5(7, 8);

	std::cout << "Triangle abc:" << std::endl;
	std::cout << "* a coordinates = " << a << std::endl;
	std::cout << "* b coordinates = " << b << std::endl;
	std::cout << "* c coordinates = " << c << std::endl << std::endl;
	
	std::cout << "Point p1" << p1;
	if (bsp(a, b, c, p1))
		std::cout << " is part of the triangle" << std::endl;
	else
		std::cout << " is not part of the triangle" << std::endl;

	std::cout << "Point p2" << p2;
	if (bsp(a, b, c, p2))
		std::cout << " is part of the triangle" << std::endl;
	else
		std::cout << " is not part of the triangle" << std::endl;

	std::cout << "Point p3" << p3;
	if (bsp(a, b, c, p3))
		std::cout << " is part of the triangle" << std::endl;
	else
		std::cout << " is not part of the triangle" << std::endl;

	std::cout << "Point p4" << p4;
	if (bsp(a, b, c, p4))
		std::cout << " is part of the triangle" << std::endl;
	else
		std::cout << " is not part of the triangle" << std::endl;

	std::cout << "Point p5" << p5;
	if (bsp(a, b, c, p5))
		std::cout << " is part of the triangle" << std::endl;
	else
		std::cout << " is not part of the triangle" << std::endl;
	
	return 0;
}