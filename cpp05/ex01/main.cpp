#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main( void )
{
	Bureaucrat h ("harry", 150);
	Bureaucrat h2 (h);
	Bureaucrat h3 ("geoff", 1);
	Form f ("laissez-passer A-38", 8, 150);

	std::cout << h++ << std::endl;
	std::cout << h << std::endl;
	std::cout << --h << std::endl;
	try
	{
		std::cout << h2-- << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << h2 << std::endl;
	std::cout << h3 << std::endl;
	try
	{
		std::cout << h3++ << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << h3 << std::endl;

	try
	{
		h.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	h3.signForm(f);
	h2.signForm(f);
	return 0;
}
