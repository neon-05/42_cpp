#include "Bureaucrat.hpp"

const int Bureaucrat::_grade_max = 1;
const int Bureaucrat::_grade_min = 150;

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "grade too high, must be between 1 and 150"; }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return "grade too low, must be between 1 and 150"; }

Bureaucrat::Bureaucrat( std::string name, int grade): _name(name), _grade(grade)
{
	if (_grade < _grade_max)
	{
		_grade = _grade_max;
		throw(Bureaucrat::GradeTooHighException());
	}
	else if (_grade > _grade_min)
	{
		_grade = _grade_min;
		throw(Bureaucrat::GradeTooLowException());
	}
}

Bureaucrat::Bureaucrat( Bureaucrat& other ): _name(other._name), _grade(other._grade) {}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat& other )
{
	_grade = other._grade;
	return *this;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& k )
{
	return os << k.getName() << "(grade: " << k.getGrade() << ")";
}

Bureaucrat&	Bureaucrat::operator++( void )
{
	_grade--;
	if (_grade < _grade_max)
	{
		_grade = _grade_max;
		throw(Bureaucrat::GradeTooHighException());
	}
	return *this;
}

Bureaucrat&	Bureaucrat::operator--( void )
{
	_grade++;
	if (_grade > _grade_min)
	{
		_grade = _grade_min;
		throw(Bureaucrat::GradeTooLowException());
	}
	return *this;
}

Bureaucrat	Bureaucrat::operator++( int )
{
	Bureaucrat cpy = *this;
	_grade--;
	if (_grade < _grade_max)
	{
		_grade = _grade_max;
		throw(Bureaucrat::GradeTooHighException());
	}
	return cpy;
}

Bureaucrat	Bureaucrat::operator--( int )
{
	Bureaucrat cpy = *this;
	_grade++;
	if (_grade > _grade_min)
	{
		_grade = _grade_min;
		throw(Bureaucrat::GradeTooLowException());
	}
	return cpy;
}

const std::string&	Bureaucrat::getName() const { return _name; }
int					Bureaucrat::getGrade() const { return _grade; }

Bureaucrat::~Bureaucrat() {}
