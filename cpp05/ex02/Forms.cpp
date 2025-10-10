#include "Forms.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
	AForm("Shrubbery creation form", 145, 137, target)
	{}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void	ShrubberyCreationForm::execute( const Bureaucrat& bureaucrat ) const
{
	if (bureaucrat.getGrade() > getExecGrade())
		throw(AForm::GradeTooLowException());
	if (!isSigned())
		throw(AForm::ExecUnsignedFormException());
	std::ofstream outfile ((_target + "_shrubbery").c_str());
	outfile << "  .-'- -.\n (       )\n(  ,      )\n ( \'./  .'\n  '-| |-'\n    | |\n,,,,|.|,,,\nart by  Joan Stark (Spunk)\n";
	std::cout << _target << " shrubbery successful" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ):
	AForm("Robotomy request form", 72, 45, target)
	{}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

static std::string	own_marker( const std::string& target )
{
	if (target.rbegin()[0] == 's')
		return "'";
	else
		return "'s";
}

void	RobotomyRequestForm::execute( const Bureaucrat& bureaucrat ) const
{
	if (bureaucrat.getGrade() > getExecGrade())
		throw(AForm::GradeTooLowException());
	if (!isSigned())
		throw(AForm::ExecUnsignedFormException());
	std::cout << "* drilling noises *" << std::endl;
	sleep(2);
	srand(time(0));
	std::cout << _target << own_marker(_target) << " robotomy ";
	if ((rand() % 2) == 0)
		std::cout << "is complete" << std::endl;
	else
		std::cout << "has failed" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ):
	AForm("Presidential pardon form", 25, 5, target)
	{}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute( const Bureaucrat& bureaucrat ) const
{
	if (bureaucrat.getGrade() > getExecGrade())
		throw(AForm::GradeTooLowException());
	if (!isSigned())
		throw(AForm::ExecUnsignedFormException());
	std::cout << _target << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}