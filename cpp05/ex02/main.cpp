#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Forms.hpp"
#include <iostream>

int main( void )
{
	Bureaucrat h ("harry", 150);
	Bureaucrat h3 ("geoff", 1);
	AForm *f = new ShrubberyCreationForm("home");
	AForm *f2 = new RobotomyRequestForm("f");
	AForm *f3 = new PresidentialPardonForm("this guy");

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
	h3.signForm(*f2);
	h3.execForm(*f2);
	h3.signForm(*f3);
	h3.execForm(*f3);
	delete f;
	delete f2;
	delete f3;
	return 0;
}
