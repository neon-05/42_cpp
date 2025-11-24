#include "Span.hpp"

int main()
{
	Span span(7);
	span.addNumber(1);
	try
	{
		std::cout << span.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	span.addNumber(2);
	span.addNumber(100);
	span.addNumber(3);
	span.addNumber(4);
	span.addNumber(5);
	span.addNumber(1);
	std::cout << span << std::endl;
	std::cout << span.shortestSpan() << std::endl;
	std::cout << span.longestSpan() << std::endl;
	try
	{
		span.addNumber(9999999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span	s2(span);
	std::cout << s2 << std::endl;
	return 0;
}
