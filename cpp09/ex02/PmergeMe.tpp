#include "PmergeMe.hpp"

uint jacobsthal( uint n )
{
	if (n == 0)
		return 0;
	else
		return (jacobsthal(n - 1) * 2) + ((n & 1) ? 1 : -1);
}

template <typename C>
void insert( typename C::iterator to, typename C::iterator from )
{
	while (to != from)
	{
		std::swap(*to, *from);
		to++;
	}
}
template <typename C>
static void _fordJhonsonSort( typename C::iterator begin, typename C::iterator end, uint lvl )
{
	const uint size = std::distance(begin, end);
	if (size < 2)
		return ;
	const uint half = size / 2;
	
	for (typename C::iterator it = begin; it != begin + half; it++)
	{
		if (*it > *(it + half))
			for (uint i = 0; i < (1u << lvl); i++)
				std::swap(*(it + size*i), *(it + half + size*i));
	}
	_fordJhonsonSort<C>(begin, begin + half, lvl + 1);
	typename C::iterator it = begin + (size & 0xFFFFFFFE);
	typename C::iterator cur = it;
	uint sorted_size = half;
	uint n = 0;
	while (sorted_size < (size & 0xFFFFFFFE))
	{
		while (cur == it)
		{
			uint j_diff = jacobsthal(n + 1) - jacobsthal(n);
			cur = begin + std::max((size & 0xFFFFFFFE) - j_diff, sorted_size);
		}
		insert<C>(std::lower_bound(begin, begin + sorted_size, *cur), cur);
		cur++;
		sorted_size++;
	}
	if (size & 1)
		insert<C>(std::lower_bound(begin, it, *it), it);
}


/*
Ford-Jhonson sorting algorithm

algorithm:

{
	split vec into consecutive pairs
	sort each pair individually
	sort pairs recursively according to the 2nd (largest) element
	split into 2 vectors for 1st and 2nd elements of each pair
	insert each element of the small array into the large array going from J_n to J_n-1
	insert last unpaired number
}
*/
template <typename C>
void fordJhonsonSort( C& arr )
{
	_fordJhonsonSort<C>( arr.begin(), arr.end(), 0);
}
