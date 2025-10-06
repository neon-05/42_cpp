#include "Form.hpp"

const uint Form::_grade_max = 1;
const uint Form::_grade_min = 150;

const char *Form::GradeTooHighException::what( void ) const throw() { return "grade too high, must be between 1 and 150"; }
const char *Form::GradeTooLowException::what( void ) const throw() { return "grade too low, must be between 1 and 150"; }

Form::Form( std::string name, uint sign_grade, uint exec_grade ):
	_name(name),
	_grade_sign(sign_grade),
	_grade_exec(exec_grade),
	_signed(false)
{

}

Form::Form( Form& other):
	_name(other._name),
	_grade_sign(other._grade_sign),
	_grade_exec(other._grade_exec),
	_signed(other._signed)
	{}

Form	Form::operator=( Form& other)
{
	Form ret (other);
	return ret;
}

Form::~Form( void ) {}

bool				Form::isSigned( void ) const { return _signed; }

const std::string&	Form::getName( void ) const { return _name; }
uint				Form::getSignGrade( void ) const { return _grade_sign; }
uint				Form::getExecGrade( void ) const { return _grade_exec; }

std::ostream& operator<<( std::ostream& os, const Form& form )
{
	os << form.getName() << "(";
	if (!form.isSigned())
		os << "not ";
	os << "signed)";
}