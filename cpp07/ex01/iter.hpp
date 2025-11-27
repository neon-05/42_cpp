#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template<typename T1, typename T2>
void iter( T1 *arr, const int len, void(*func)( T2& ) )
{
	if (!arr)
		return;
	for (int i = 0; i < len; i++)
		func((T2&) arr[i]);
}

#endif