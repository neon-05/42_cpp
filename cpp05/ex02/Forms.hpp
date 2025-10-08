#ifndef FORMS_HPP
#define FORMS_HPP
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm: public AForm
{
public:

	ShrubberyCreationForm( std::string );
	~ShrubberyCreationForm( void );

	void	execute( const Bureaucrat& ) const;

private:
	const std::string	_target;
};

class RobotomyRequestForm: public AForm
{
public:

	RobotomyRequestForm( std::string );
	~RobotomyRequestForm( void );

	void	execute( const Bureaucrat& ) const;
};

class PresidentialPardonForm: public AForm
{
public:

	PresidentialPardonForm( std::string );
	~PresidentialPardonForm( void );

	void	execute( const Bureaucrat& ) const;
};

#endif