#include "Point.hpp"

Point::Point( void ) : _x(), _y() {}
Point::Point( const Point& other ) : _x(other._x), _y(other._y) {}
Point::Point( const Fixed x, const Fixed y ) : _x(x), _y(y) {}
Point::~Point( void ) {}

Point& Point::operator=( Point& other )
{
	_x = other._x;
	_y = other._y;
	return *this;
}

Fixed Point::getX( void ) const { return _x; }
Fixed Point::getY( void ) const { return _y; }