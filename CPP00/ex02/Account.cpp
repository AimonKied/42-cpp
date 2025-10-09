// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                     //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts 
			  << ";total:" << _totalAmount 
			  << ";deposits:" << _totalNbDeposits 
			  << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/* Constructor fuer die Account class 
Bei erstellen von Account geht counter und totalAmout hoch und erstellung wird displayed
*/
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";created" << std::endl;
}

/* Destructor fuer die Account class
Wird am Ende aufgerufen
*/
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";amount:" << _amount 
			  << ";closed" << std::endl;
}

/* Member functions fuer die Account class
funktion zum anzeigen aktueller werte | funktion zum geld abheben | funktion fuer timestamp
funktion zum aktuellen wert checken | funktion um status auszugeben
*/
void Account::makeDeposit(int deposit) {
	int p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
			  << ";p_amount:" << p_amount 
			  << ";deposit:" << deposit 
			  << ";amount:" << _amount 
			  << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	int p_amount = _amount;
	if (_amount >= withdrawal) {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << _accountIndex 
				  << ";p_amount:" << p_amount 
				  << ";withdrawal:" << withdrawal 
				  << ";amount:" << _amount 
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
    else {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex 
				  << ";p_amount:" << p_amount 
				  << ";withdrawal:refused" << std::endl;
		return false;
	}
}

int Account::checkAmount(void) const {
	return _amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/* Private static function fuer die Account class
Funktion fuer Timestamp
*/
void Account::_displayTimestamp(void) {
	std::time_t now = std::time(0);
	std::tm* timeinfo = std::localtime(&now);
	
	std::cout << "[" << (1900 + timeinfo->tm_year)
			  << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_min
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			  << "] ";
}