#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat( std::string, int );
	Bureaucrat( Bureaucrat& );
	Bureaucrat& operator=( Bureaucrat& );
	~Bureaucrat();

	Bureaucrat& operator++( void );
	Bureaucrat& operator--( void );
	Bureaucrat operator++( int );
	Bureaucrat operator--( int );

	const std::string&	getName( void ) const;
	int					getGrade( void ) const;

	class GradeTooLowException: public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooHighException: public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	const std::string	_name;
	int					_grade;

	static const int	_grade_min;
	static const int	_grade_max;
};

std::ostream& operator<<( std::ostream&, const Bureaucrat& );

#endif