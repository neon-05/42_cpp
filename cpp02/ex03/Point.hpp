#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
public:
	Point( void );
	Point( const Point& );
	Point( const Fixed, const Fixed );
	~Point();

	Point& operator=( Point& );
	Fixed getX( void ) const;
	Fixed getY( void ) const;

private:
	Fixed _x;
	Fixed _y;
};

#endif