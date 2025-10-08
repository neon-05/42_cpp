#include "Forms.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
	AForm("Shrubbery creation form", 145, 137),
	_target(target)
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
