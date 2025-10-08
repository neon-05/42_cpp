#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
class Form;
#include "Bureaucrat.hpp"
typedef unsigned int uint;

class Form
{
public:
	Form( std::string, uint, uint );
	Form( Form& );
	Form& operator=( Form& );
	~Form( void );

	bool				isSigned( void ) const;
	const std::string&	getName( void ) const;
	uint				getSignGrade( void ) const;
	uint				getExecGrade( void ) const;

	void				beSigned( const Bureaucrat& );

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
	const uint			_grade_sign;
	const uint			_grade_exec;
	bool				_signed;

	static const uint	_grade_min;
	static const uint	_grade_max;
};

std::ostream& operator<<( std::ostream&, const Form& );

#endif