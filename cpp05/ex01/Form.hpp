#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
public:
	Form( std::string, uint, uint );
	Form( Form& );
	Form operator=( Form& );
	~Form( void );

	bool				isSigned( void ) const;
	const std::string&	getName( void ) const;
	uint				getSignGrade( void ) const;
	uint				getExecGrade( void ) const;

	void				beSigned( Bureaucrat& );

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
	const std::string	_name;
	bool				_signed;
	const uint			_grade_sign;
	const uint			_grade_exec;

	static const uint	_grade_min;
	static const uint	_grade_max;
};

std::ostream& operator<<( std::ostream&, const Form& );

#endif