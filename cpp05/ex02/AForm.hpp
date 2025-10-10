#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <iostream>
class AForm;
#include "Bureaucrat.hpp"
typedef unsigned int uint;

class AForm
{
public:
	AForm( std::string, uint, uint, std::string );
	AForm( AForm& );
	AForm& operator=( AForm& );
	virtual ~AForm( void );

	bool				isSigned( void ) const;
	const std::string&	getName( void ) const;
	uint				getSignGrade( void ) const;
	uint				getExecGrade( void ) const;

	void				beSigned( const Bureaucrat& );
	virtual void		execute( const Bureaucrat& ) const = 0;

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

	class ExecUnsignedFormException: public std::exception
	{
	public:
		const char *what( void ) const throw();
	};

protected:
	const std::string	_target;

private:
	static uint			_clamp( uint );

	const std::string	_name;
	const uint			_grade_sign;
	const uint			_grade_exec;
	bool				_signed;

	static const uint	_grade_min;
	static const uint	_grade_max;

};

std::ostream& operator<<( std::ostream&, const AForm& );

#endif