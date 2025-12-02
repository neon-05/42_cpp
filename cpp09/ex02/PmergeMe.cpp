#include "PmergeMe.hpp"

typedef std::vector<std::pair<int, int> > PairVec;

static void print( std::vector<std::pair<int, int> >& vec )
{
	std::vector<std::pair<int, int> >::iterator it = vec.begin();
	while (it != vec.end())
	{
		std::cout << "(" << it->first << ", " << it->second << ")" << std::endl;
		it++;
	}
}

static void sort( std::vector<std::pair<int, int> >& v )
{
	std::swap(v[0], v[3]);
	std::swap(v[1], v[2]);
}

uint jacobsthal( uint n )
{
	if (n == 0)
		return 0;
	else
		return (jacobsthal(n - 1) * 2) + ((n & 1) ? 1 : -1);
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
void fordJhonsonSort( std::vector<int>& vec )
{
	const uint size = vec.size();
	if (size < 2)
		return ;
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
	vec.insert(std::lower_bound(vec.begin(), vec.end(), extra), extra);
}
