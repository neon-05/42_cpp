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
void fordJhonsonSort( typename C::iterator begin, typename C::iterator end, uint lvl )
{
	const uint size = std::distance(begin, end);
	if (size < 2)
		return ;
	//typedef typename C::value_type T;
	const uint half = size / 2;
	
	for (typename C::iterator it = begin; it != begin + half; it++)
	{
		if (*it > *(it + half))
			for (uint i = 0; i < (1u << lvl); i++)
				std::swap(*(it + size*i), *(it + half + size*i));
	}
	fordJhonsonSort<C>(begin, begin + half, lvl + 1);
	typename C::iterator it = begin + (size & 0xFFFFFFFE);
	typename C::iterator new_end = begin + half;
	uint to_go = half;
	uint n = 2;
	while ( new_end != it )
	{
		insert<C>(std::lower_bound(begin, new_end, *it), it);
		new_end++;
		n++;
		to_go--;
	}
	it++;
	//insert<C>(std::lower_bound(begin, new_end, *it), it);


/*









	PairVec	pairs;
	int		extra = (vec.size() & 1) ? vec.back() : -1;

	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end() && it != vec.end() - 1; it += 2)
	{
		std::pair<int, int>	p(*it, *(it + 1));
		if (p.first > p.second)
			std::swap(p.first, p.second);
		pairs.insert(pairs.end(), p);
	}
	vec.clear();
	sort(pairs);
	print(pairs);
	if (vec.size() & 1)
		std::cout << extra << std::endl;

	for (PairVec::const_iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		vec.push_back(it->second);
		std::cout << it->second << ", ";
	}
	std::cout << std::endl;
	
	vec.insert(vec.begin(), pairs[0].first);
	std::cout << vec[0] << "<-" << std::endl;
	int	old_j;
	int	new_j = 1;
	int	offset = 0;
	for (int n = 3; jacobsthal(n) < size; n++)
	{
		old_j = new_j;
		new_j = jacobsthal(n);
		for (int i = new_j; i > old_j; i--)
		{
			if (i <= (int) pairs.size())
			{
				vec.insert(std::lower_bound(vec.begin(), vec.begin() + i + offset++, pairs[i - 1].first), pairs[i - 1].first);
				std::cout << pairs[i - 1].first << "| ";
				for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
					std::cout << *it << ", ";
				std::cout << std::endl;
			}
		}
	}
	vec.insert(std::lower_bound(vec.begin(), vec.end(), extra), extra);*/
}
