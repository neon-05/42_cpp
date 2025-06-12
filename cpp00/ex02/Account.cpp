#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	this->_accountIndex = _nbAccounts;
	this->_nbAccounts++;
	this->_amount = 0;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}
Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	this->_totalAmount -= this->_amount;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	int p_amount = this->_amount;
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = this->_amount;
	bool canWithdraw = withdrawal <= p_amount;
	if (canWithdraw)
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
	}

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << p_amount << ";";
	if (canWithdraw)
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		std::cout << "amount:" << this->_amount << ";";
		std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	}
	else
		std::cout << "withdrawal:refused" << std::endl;

	return (canWithdraw);
}

int		Account::checkAmount( void ) const { return (this->_amount); }

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int	Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}


void	Account::_displayTimestamp( void )
{
	time_t timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);

	std::cout << "[";
	std::cout << datetime.tm_year+1900;
	if (datetime.tm_mon < 10)
		std::cout << "0";
	std::cout << datetime.tm_mon;
	if (datetime.tm_mday < 10)
		std::cout << "0";
	std::cout << datetime.tm_mday;
	std::cout << "_";
	if (datetime.tm_hour < 10)
		std::cout << "0";
	std::cout << datetime.tm_hour;
	if (datetime.tm_min < 10)
		std::cout << "0";
	std::cout << datetime.tm_min;
	if (datetime.tm_sec < 10)
		std::cout << "0";
	std::cout << datetime.tm_sec;
	std::cout << "] ";
}
