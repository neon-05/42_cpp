#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) { std::cout << "default" << std::endl; }
Fixed::Fixed( const Fixed& other ) : _value(other._value) { std::cout << "copy" << std::endl; }
Fixed::Fixed( const int n ) : _value(n << _fractional_bits) { std::cout << "from int" << std::endl; }
Fixed::Fixed( const float f ) : _value(f * (float)(1 << _fractional_bits)) { std::cout << "from float" << std::endl; }
Fixed::~Fixed() { std::cout << "delete" << std::endl; }

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "copy assignment" << std::endl;
	_value = other._value;
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Fixed& x ) { return os << x.toFloat(); }

int Fixed::toInt( void ) const { return _value >> _fractional_bits; }
float Fixed::toFloat( void ) const { return (float) _value / (1 << _fractional_bits); }

int Fixed::getRawBits( void ) const { std::cout << "get" << std::endl; return _value; }
void Fixed::setRawBits( const int raw ) { std::cout << "set" << std::endl; _value = raw; }
