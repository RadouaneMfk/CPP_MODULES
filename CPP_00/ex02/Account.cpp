#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	std::cout << "index:" << Account::_nbAccounts << ";amount:" << initial_deposit << ";created" 
	<< std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_amount = initial_deposit;
	Account::_accountIndex += Account::_nbAccounts;
	Account::_nbAccounts++;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" 
	<< std::endl;
}

void Account::_displayTimestamp( void ) {
	std::time_t now = std::time(NULL);
	std::tm *timeInfo = std::localtime(&now);
	std::cout << '[' << timeInfo->tm_year + 1900 <<
	std::setw(2) << std::setfill('0') << timeInfo->tm_mon + 1
	<< std::setw(2) << std::setfill('0') << timeInfo->tm_mday << '_'
	<< std::setw(2) << std::setfill('0') << timeInfo->tm_hour
	<< std::setw(2) << std::setfill('0') << timeInfo->tm_min
	<< std::setw(2) << std::setfill('0') << timeInfo->tm_sec
	<< "] ";
}

int Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

int Account::checkAmount( void ) const {
	return Account::_amount;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	<< ";total:" << getTotalAmount() << ";deposits:"
	<< Account::_totalNbDeposits << ";withdrawals:"
	<< Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex <<
	";amount:" << checkAmount() << ";deposits:" <<
	Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals <<
	std::endl;
}

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	Account::_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	int prev_amount = checkAmount();
	Account::_amount += deposit;
	std::cout << "index:" << Account::_accountIndex <<
	";p_amount:" << prev_amount << ";deposit:" <<
	deposit << ";amount:" << checkAmount() <<
	";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	if (withdrawal > checkAmount()) {
		std::cout << "index:" << Account::_accountIndex <<
		";p_amount:" << checkAmount() << ";withdrawal:refused" << 
		std::endl;
		return (false);
	}
	Account::_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	int prev_amount = Account::_amount;
	Account::_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "index:" << Account::_accountIndex <<
	";p_amount:" << prev_amount << ";withdrawal:" <<
	withdrawal << ";amount:" << checkAmount() <<
	";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return (true);
}
