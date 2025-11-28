#include "Span.hpp"
#include <vector>

int main()
{
	Span span(7);
	span.addNumber(1);
	std::cout << "span :\t\t" << span << std::endl;
	try
	{
		std::cout << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<int> vec;
	srand(time(NULL));
	for (int i = 1; i < span.getCapacity(); i++)
		vec.insert(vec.end(), rand());
	span.addNumbers(vec.begin(), vec.end());

	std::cout << "span :\t\t" << span << std::endl;
	std::cout << "min span :\t" << span.shortestSpan() << std::endl;
	std::cout << "max span :\t" << span.longestSpan() << std::endl;

	try
	{
		span.addNumber(9999999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span	s2(span);
	std::cout << "span :\t\t" << s2 << std::endl;
	return 0;
}
