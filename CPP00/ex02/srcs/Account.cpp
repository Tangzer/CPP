#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return _nbAccounts;
}

int	Account::getTotalAmount(void) {
	return _totalAmount;
}

int	Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit) {
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";withdrawal:";
	if (_amount - withdrawal < 0)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	else
	{
		std::cout << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		std::cout << ";amount:" << checkAmount();
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return true;
	}
}

int		Account::checkAmount(void) const {
	return this->_amount;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t timeptr = time(NULL);
	struct tm *time = localtime(&timeptr);

	std::cout << "[" << time->tm_year + 1900;
	if (time->tm_mon < 10)
		std::cout << 0;
	std::cout << time->tm_mon;
	if (time->tm_mday < 10)
		std::cout << 0;
	std::cout << time->tm_mday << "_";
	if (time->tm_hour < 10)
		std::cout << 0;
	std::cout << time->tm_hour;
	if (time->tm_min < 10)
		std::cout << 0;
	std::cout << time->tm_min;
	if (time->tm_sec < 10)
		std::cout << 0;
	std::cout << time->tm_sec << "] ";
}