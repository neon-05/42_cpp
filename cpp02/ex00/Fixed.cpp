#include "Fixed.hpp"
#include <iostream>

const int Fixed::_fractional_bits = 8;

Fixed::Fixed( void ) : _value(0) { std::cout << "default" << std::endl; }
Fixed::Fixed( const Fixed& other ) : _value(other._value) { std::cout << "copy" << std::endl; }
Fixed::~Fixed() { std::cout << "delete" << std::endl; }

Fixed& Fixed::operator=( const Fixed& other )
{
	std::cout << "copy assignment" << std::endl;
	_value = other._value;
	return *this;
}

int Fixed::getRawBits( void ) const { std::cout << "get" << std::endl; return _value; }
void Fixed::setRawBits( const int raw ) { std::cout << "set" << std::endl; _value = raw; }
