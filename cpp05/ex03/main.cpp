#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Forms.hpp"
#include "Intern.hpp"
#include <iostream>

int main( void )
{
	Intern intern;
	AForm *f1;
	AForm *f2;
	AForm *f3;

	f1 = intern.makeForm("shrubbery creation", "professional");
	f2 = intern.makeForm("robotomy request", "Bender");
	try
	{
		f3 = intern.makeForm("laissez-passer A-38", "guichet 3");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	f3 = intern.makeForm("presidential pardon", "joe");

	delete f1;
	delete f2;
	delete f3;
	return 0;
}
