#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) {}
Fixed::Fixed( const Fixed& other ) : _value(other._value) {}
Fixed::Fixed( const int n ) : _value(n << _fractional_bits) {}
Fixed::Fixed( const float f ) : _value(f * (float)(1 << _fractional_bits)) {}
Fixed::~Fixed() {}

Fixed& Fixed::operator=( const Fixed& other ) { _value = other._value; return *this; }
std::ostream& operator<<( std::ostream& os, const Fixed& other ) { return os << other.toFloat(); }

bool Fixed::operator>( const Fixed other ) const { return _value > other._value; }
bool Fixed::operator<( const Fixed other ) const { return _value < other._value; }
bool Fixed::operator>=( const Fixed other ) const { return _value >= other._value; }
bool Fixed::operator<=( const Fixed other ) const { return _value <= other._value; }
bool Fixed::operator==( const Fixed other ) const { return _value == other._value; }
bool Fixed::operator!=( const Fixed other ) const { return _value != other._value; }

Fixed Fixed::operator+( const Fixed other ) const
{
	Fixed r;
	r._value = _value + other._value;
	return r;
}

Fixed Fixed::operator-( const Fixed other ) const
{
	Fixed r;
	r._value = _value - other._value;
	return r;
}

Fixed Fixed::operator*( const Fixed other ) const
{
	Fixed r;
	r._value = (long) _value * other._value >> _fractional_bits;
	return r;
}

Fixed Fixed::operator/( const Fixed other ) const
{
	Fixed r;
	r._value = ((long) _value << _fractional_bits) / other._value;
	return r;
}

Fixed Fixed::operator++( void ) { _value++; return *this; }
Fixed Fixed::operator--( void ) { _value--; return *this; }
Fixed Fixed::operator++( int ) { Fixed r = *this; _value++; return r; }
Fixed Fixed::operator--( int ) { Fixed r = *this; _value--; return r; }

Fixed& Fixed::min( Fixed& a, Fixed& b ) { return (a < b) ? a : b; }
Fixed& Fixed::max( Fixed& a, Fixed& b ) { return (a > b) ? a : b; }
const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) { return (a < b) ? a : b; }
const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) { return (a > b) ? a : b; }

int Fixed::toInt( void ) const { return _value >> _fractional_bits; }
float Fixed::toFloat( void ) const { return (float) _value / (1 << _fractional_bits); }

int Fixed::getRawBits( void ) const { return _value; }
void Fixed::setRawBits( const int raw ) { _value = raw; }
