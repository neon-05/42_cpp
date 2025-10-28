#ifndef INTERN_HPP
#define INTERN_HPP
#include "Forms.hpp"
#include "AForm.hpp"

typedef AForm	*(*form_factory)( std::string );

class Intern
{
public:
	Intern( void );
	Intern( Intern& );
	Intern& operator=( Intern& );
	~Intern( void );

	AForm	*makeForm( std::string, std::string );

	class FormNameNotDeclared: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

private:
	static const int			_total_form_types;
	static const std::string	_form_names[];
	static const form_factory	_form_funcs[];
};


#endif