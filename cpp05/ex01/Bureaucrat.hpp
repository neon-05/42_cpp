#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
class Bureaucrat;
#include "Form.hpp"
typedef unsigned int uint;


class Bureaucrat
{
public:
	Bureaucrat( std::string, uint );
	Bureaucrat( Bureaucrat& );
	Bureaucrat& operator=( Bureaucrat& );
	~Bureaucrat( void );

	Bureaucrat& operator++( void );
	Bureaucrat& operator--( void );
	Bureaucrat operator++( int );
	Bureaucrat operator--( int );

	const std::string&	getName( void ) const;
	uint				getGrade( void ) const;

	void				signForm( Form& ) const;

	class GradeTooLowException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

	class GradeTooHighException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

private:

	static uint			_clamp( uint );

	const std::string	_name;
	uint				_grade;

	static const uint	_grade_min;
	static const uint	_grade_max;
};

std::ostream& operator<<( std::ostream&, const Bureaucrat& );

#endif