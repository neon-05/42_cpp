#include "PmergeMe.hpp"
#include <ctime>
#include <cstdlib>

int main( void )
{
	std::vector<int>	vec;
	srand(time(NULL));
	for (int i = 0; i < 8; i++)
		vec.insert(vec.end(), 9-i);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	fordJhonsonSort<std::vector<int> >(vec.begin(), vec.end(), 0);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	return 0;
}

