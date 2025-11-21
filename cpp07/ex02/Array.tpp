#include "Array.hpp"

template <typename T>
const char	*Array<T>::OutOfBoundsException::what( void ) const throw() { return "index out of bounds"; }

template <typename T>
Array<T>::Array( uint n ) : _len(n), _arr(new T[n]() ) {}

template <typename T>
Array<T>::Array( const Array& other) : _len(other._len), _arr(new T[_len]())
{
	for (uint i = 0; i < _len; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T>::~Array( void )
{
	delete[] _arr;
}

template <typename T>
Array<T>&	Array<T>::operator=( const Array& other )
{
	if (_arr)
		delete[] _arr;
	_len = other._len;
	_arr = new T[_len]();
	for (uint i = 0; i < _len; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
T	Array<T>::operator[]( uint i ) const
{
	if (i >= _len)
		throw (Array::OutOfBoundsException());
	return (_arr[i]);
}

template <typename T>
T&	Array<T>::operator[]( uint i )
{
	if (i >= _len)
		throw (Array::OutOfBoundsException());
	return (_arr[i]);
}

template <typename T>
uint	Array<T>::getLen( void ) const { return _len; }

template <typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& arr )
{
	uint max = arr.getLen();
	for (uint i = 0; i < max; i++)
	{
		os << ((i == 0) ? "{" : ", ") << arr[i];
	}
	os << '}';
	return os;
}
