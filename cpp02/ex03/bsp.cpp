#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

bool bsp( const Point a, const Point b, const Point c, const Point point );
static Fixed point_dist_line( const Point a, const Point b, const Point point );

int main( void )
{
	Point a(0, 0);
	Point b(1, 0);
	Point c(0, 1);
	Point P(0.3f, 0.4f);
	std::cout << (bsp(a, c, b, P) ? "yes" : "no") << std::endl;
	return 0;
}

bool bsp( const Point a, const Point b, const Point c, const Point point )
{
	Fixed distAB = point_dist_line(a, b, point);
	Fixed distBC = point_dist_line(b, c, point);
	Fixed distCA = point_dist_line(c, a, point);
	int sideChecks = (distAB > 0) + (distBC > 0) + (distCA > 0);
	if ( distAB == 0 || distBC == 0 || distCA == 0 )
		return false;
	else
		return (sideChecks == 0 || sideChecks == 3);
}

/* formula for signed distance to a line defined by two points */
static Fixed point_dist_line( const Point a, const Point b, const Point point )
{
	return
		(a.getY() - b.getY()) * (point.getX() - a.getX()) -
		(a.getX() - b.getX()) * (point.getY() - a.getY())
	;
}