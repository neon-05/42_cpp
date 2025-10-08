#include "Bureaucrat.hpp"

const uint Bureaucrat::_grade_max = 1;
const uint Bureaucrat::_grade_min = 150;

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() { return "grade too high, must be between 1 and 150"; }
const char *Bureaucrat::GradeTooLowException::what( void ) const throw() { return "grade too low, must be between 1 and 150"; }

Bureaucrat::Bureaucrat( std::string name, uint grade): _name(name), _grade(grade)
{
	if (grade < _grade_max)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > _grade_min)
		throw(Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat( Bureaucrat& other ): _name(other._name), _grade(other._grade) {}

Bureaucrat&	Bureaucrat::operator=( Bureaucrat& other )
{
	_grade = _clamp(other._grade);

	return *this;
}

std::ostream& operator<<( std::ostream& os, const Bureaucrat& k )
{
	return os << k.getName() << " (grade: " << k.getGrade() << ")";
}

Bureaucrat&	Bureaucrat::operator++( void )
{
	if (_grade - 1 < _grade_max)
		throw(Bureaucrat::GradeTooHighException());
	_grade--;
	return *this;
}

Bureaucrat&	Bureaucrat::operator--( void )
{
	if (_grade + 1 > _grade_min)
		throw(Bureaucrat::GradeTooLowException());
	_grade++;
	return *this;
}

Bureaucrat	Bureaucrat::operator++( int )
{
	Bureaucrat cpy = *this;
	if (_grade - 1 < _grade_max)
		throw(Bureaucrat::GradeTooHighException());
	_grade--;
	return cpy;
}

Bureaucrat	Bureaucrat::operator--( int )
{
	Bureaucrat cpy = *this;
	if (_grade + 1 > _grade_min)
		throw(Bureaucrat::GradeTooLowException());
	_grade++;
	return cpy;
}

uint			Bureaucrat::_clamp( uint x )
{
	if (x < _grade_max)
		return _grade_max;
	else if (x > _grade_min)
		return _grade_min;
	else
		return x;
}

const std::string&	Bureaucrat::getName( void ) const { return _name; }
uint				Bureaucrat::getGrade( void ) const { return _grade; }
void				Bureaucrat::signForm( Form& form ) const { form.beSigned(*this); }

Bureaucrat::~Bureaucrat( void ) {}
