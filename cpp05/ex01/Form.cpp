#include "Form.hpp"

const uint Form::_grade_max = 1;
const uint Form::_grade_min = 150;

const char *Form::GradeTooHighException::what( void ) const throw() { return "grade too high"; }
const char *Form::GradeTooLowException::what( void ) const throw() { return "grade too low"; }

Form::Form( std::string name, uint sign_grade, uint exec_grade ):
	_name(name),
	_grade_sign(_clamp(sign_grade)),
	_grade_exec(_clamp(exec_grade)),
	_signed(false)
{
	if (sign_grade < _grade_max)
		throw(Form::GradeTooHighException());
	else if (sign_grade > _grade_min)
		throw(Form::GradeTooLowException());

	if (exec_grade < _grade_max)
		throw(Form::GradeTooHighException());
	else if (exec_grade > _grade_min)
		throw(Form::GradeTooLowException());
}

Form::Form( Form& other ):
	_name(other._name),
	_grade_sign(other._grade_sign),
	_grade_exec(other._grade_exec),
	_signed(other._signed)
	{}

Form	Form::operator=( Form& other )
{
	Form ret (other);
	return ret;
}

Form::~Form( void ) {}

uint			Form::_clamp( uint x )
{
	if (x < _grade_max)
		return _grade_max;
	else if (x > _grade_min)
		return _grade_min;
	else
		return x;
}

bool				Form::isSigned( void ) const { return _signed; }

const std::string&	Form::getName( void ) const { return _name; }
uint				Form::getSignGrade( void ) const { return _grade_sign; }
uint				Form::getExecGrade( void ) const { return _grade_exec; }

void				Form::beSigned( const Bureaucrat& bureaucrat )
{
	if (bureaucrat.getGrade() <= _grade_sign)
	{
		_signed = true;
		std::cout << bureaucrat << " signed form " << *this << std::endl;
	}
	else
	{
		std::cout << bureaucrat << " could not sign form " << *this << std::endl;
		throw(Form::GradeTooLowException());
	}
}

std::ostream& operator<<( std::ostream& os, const Form& form )
{
	os << form.getName() << " (";
	if (!form.isSigned())
		os << "not ";
	os << "signed)";
	return os;
}