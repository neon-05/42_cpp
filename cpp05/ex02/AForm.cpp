#include "AForm.hpp"

const uint AForm::_grade_max = 1;
const uint AForm::_grade_min = 150;

const char *AForm::GradeTooHighException::what( void ) const throw() { return "grade too high"; }
const char *AForm::GradeTooLowException::what( void ) const throw() { return "grade too low"; }
const char *AForm::ExecUnsignedFormException::what( void ) const throw() { return "attempted to execute an unsigned form"; }

AForm::AForm( std::string name, uint sign_grade, uint exec_grade ):
	_name(name),
	_grade_sign(_clamp(sign_grade)),
	_grade_exec(_clamp(exec_grade)),
	_signed(false)
{
	if (sign_grade < _grade_max)
		throw(AForm::GradeTooHighException());
	else if (sign_grade > _grade_min)
		throw(AForm::GradeTooLowException());

	if (exec_grade < _grade_max)
		throw(AForm::GradeTooHighException());
	else if (exec_grade > _grade_min)
		throw(AForm::GradeTooLowException());
}

AForm::AForm( AForm& other ):
	_name(other._name),
	_grade_sign(other._grade_sign),
	_grade_exec(other._grade_exec),
	_signed(other._signed)
	{}

AForm&	AForm::operator=( AForm& )
{
	std::cerr << "WARNING - can't modify form data after creation" << std::endl;
	return *this;
}

AForm::~AForm( void ) {}

uint			AForm::_clamp( uint x )
{
	if (x < _grade_max)
		return _grade_max;
	else if (x > _grade_min)
		return _grade_min;
	else
		return x;
}

bool				AForm::isSigned( void ) const { return _signed; }

const std::string&	AForm::getName( void ) const { return _name; }
uint				AForm::getSignGrade( void ) const { return _grade_sign; }
uint				AForm::getExecGrade( void ) const { return _grade_exec; }

void				AForm::beSigned( const Bureaucrat& bureaucrat )
{
	if (_signed)
		std::cout << "form " << *this << " is already signed" << std::endl;
	else if (bureaucrat.getGrade() <= _grade_sign)
	{
		_signed = true;
		std::cout << bureaucrat << " signed form " << *this << std::endl;
	}
	else
	{
		std::cout << bureaucrat << " could not sign form " << *this << std::endl;
		throw(AForm::GradeTooLowException());
	}
}

std::ostream& operator<<( std::ostream& os, const AForm& form )
{
	os << form.getName() << " (";
	if (!form.isSigned())
		os << "not ";
	os << "signed)";
	return os;
}