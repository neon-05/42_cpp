#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) {}
Fixed::Fixed( const Fixed& other ) : _value(other._value) {}
Fixed::Fixed( const int n ) : _value(n << _fractional_bits) {}
Fixed::Fixed( const float f ) : _value(f * (float)(1 << _fractional_bits)) {}
Fixed::~Fixed() {}

Fixed& Fixed::operator=( const Fixed& other ) { _value = other._value; return *this; }
std::ostream& operator<<( std::ostream& os, const Fixed& other ) { return os << other.toFloat(); }

int Fixed::toInt( void ) const { return _value >> _fractional_bits; }
float Fixed::toFloat( void ) const { return (float) _value / (1 << _fractional_bits); }

int Fixed::getRawBits( void ) const { return _value; }
void Fixed::setRawBits( const int raw ) { _value = raw; }
