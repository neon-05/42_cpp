#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main( void )
{
	int	vec_len = 20;
	std::vector<int> v(vec_len);
	std::vector<int>::iterator it;

	for (int i = 0; i < vec_len; i++)
	{
		v[i] = vec_len - i;
		std::cout << ((i == 0) ? "{" : ", ") << v[i];
	}
	std::cout << '}' << std::endl;

	it = easyfind(v, 9);
	std::cout << *it << std::endl;

	try
	{
		it = easyfind(v, 222);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
