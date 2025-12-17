#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

void	Account::_displayTimestamp(void) {
	time_t timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);

	std::cout << "[" << 1900 + datetime.tm_year
			<< datetime.tm_mon
			<< datetime.tm_mday << "_"
			<< datetime.tm_hour
			<< datetime.tm_min
			<< datetime.tm_sec << "] ";
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount + deposit << ";"
		<< "nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits++;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	this->_displayTimestamp();
	if (withdrawal > this->_amount) {
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:refused" << std::endl;
		return (false);
	}
	else {
		std::cout << "index:" << this->_accountIndex << ";"
			<< "p_amount:" << this->_amount << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount - withdrawal << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_nbWithdrawals++;
		this->_totalNbWithdrawals++;
		return (true);
	}
}

int	Account::checkAmount() const {
	std::cout << "Check amount" << std::endl;
	return (0);
}

void	Account::displayStatus() const {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit): _accountIndex(this->_nbAccounts), _amount(initial_deposit),
					_nbDeposits(0), _nbWithdrawals(0){
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
	this->_totalAmount += this->_amount;
	this->_nbAccounts++;
}

Account::~Account(void) {
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}
