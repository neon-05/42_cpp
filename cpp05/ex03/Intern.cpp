#include "Forms.hpp"
#include "Intern.hpp"

static AForm	*_makeShrubberyForm( std::string target ) { return new ShrubberyCreationForm( target ); }
static AForm	*_makeRobotomyForm( std::string target ) { return new RobotomyRequestForm( target ); }
static AForm	*_makePrPardonForm( std::string target ) { return new PresidentialPardonForm( target ); }

const int			Intern::_total_form_types = 3;
const form_factory	Intern::_form_funcs[] = {_makeShrubberyForm, _makeRobotomyForm, _makePrPardonForm};
const std::string	Intern::_form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

Intern::Intern( void ) {}
Intern::Intern( Intern& ) {}
Intern::~Intern( void ) {}
Intern&	Intern::operator=( Intern& ) { return *this; }

const char	*Intern::FormNameNotDeclared::what( void ) const throw() { return "tried making an undeclared form"; }

AForm	*Intern::makeForm( std::string type, std::string target )
{
	for (int i = 0; i < _total_form_types; i++)
	{
		if (_form_names[i] == type)
		{
			std::cout << "created " << type << " form for " << target << std::endl;
			return (*_form_funcs[i])(target);
		}
	}
	throw (Intern::FormNameNotDeclared());
	return NULL;
}
