#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Forms.hpp"
#include <iostream>

int main( void )
{
	Bureaucrat h ("harry", 150);
	Bureaucrat h3 ("geoff", 1);
	AForm *f = new ShrubberyCreationForm("tree");
	AForm *f2;

	try
	{
		h.execForm(*f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	try
	{
		h.signForm(*f);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	h3.signForm(*f);
	h.signForm(*f);
	h3.execForm(*f);
	delete f;
	return 0;
}
