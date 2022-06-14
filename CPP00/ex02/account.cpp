#include <iostream>
#include <iomanip>
#include "account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(){
	return Account::_nbAccounts;
}

int Account::getTotalAmount(){
	return Account::_totalAmount;
}

int Account::getNbDeposits(){
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(){
	return Account::_totalNbWithdrawals;
}

int Account::checkAmount() const{
	return this->_amount;
}

void Account::_displayTimestamp(){
	std::time_t t = std::time(NULL);
	std::tm *const Time = std::localtime(&t);

	std::cout << std::setfill('0') << "["
	<< std::setw(4) << 1900 + Time->tm_year
	<< std::setw(2) << Time->tm_mon + 1
	<< std::setw(2) << Time->tm_mday << "_"
	<< std::setw(2) << Time->tm_hour
	<< std::setw(2) << Time->tm_min
	<< std::setw(2) << Time->tm_sec << "]";
}

Account::Account(int initial_deposit) : _nbDeposits(0), _nbWithdrawals(0){
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;

	this->_amount = initial_deposit;
	Account::_totalAmount += this->_amount;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";created:" << std::endl;
	if (this->_accountIndex == 7)
		std::cout << std::endl;
}

void Account::displayAccountsInfos(){
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
	<< ";total:" << Account::getTotalAmount()
	<< ";deposits:" << Account::getNbDeposits()
	<< ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit){
	Account::_displayTimestamp();

	this->_nbDeposits++;
	Account::_totalNbDeposits++;

	Account::_totalAmount += deposit;

	std::cout << "index:" << this->_accountIndex
	<< ";p_amount" << this->_amount
	<< ";withdrawal:" << deposit;

	this->_amount += deposit;
	std::cout << ";amount:" << this->_amount
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	if (this->_accountIndex == 7)
		std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	Account::_displayTimestamp();

	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount;
	if (withdrawal > Account::checkAmount())
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	else
	{
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		this->_nbWithdrawals++;

		std::cout << ";withdrawal:" << withdrawal;
		this->_amount -= withdrawal;
		std::cout << ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		if (this->_accountIndex == 7)
			std::cout << std::endl;
	}
	return true;
}

void Account::displayStatus() const{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
	if (this->_accountIndex == 7)
		std::cout << std::endl;
}

Account::~Account(){
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";closed:" << std::endl;
}
// [19920104_091532] index:0;amount:42;created
// [19920104_091532] index:1;amount:54;created
// [19920104_091532] index:2;amount:957;created
// [19920104_091532] index:3;amount:432;created
// [19920104_091532] index:4;amount:1234;created
// [19920104_091532] index:5;amount:0;created
// [19920104_091532] index:6;amount:754;created
// [19920104_091532] index:7;amount:16576;created

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
// [19920104_091532] index:1;amount:54;deposits:0;withdrawals:0
// [19920104_091532] index:2;amount:957;deposits:0;withdrawals:0
// [19920104_091532] index:3;amount:432;deposits:0;withdrawals:0
// [19920104_091532] index:4;amount:1234;deposits:0;withdrawals:0
// [19920104_091532] index:5;amount:0;deposits:0;withdrawals:0
// [19920104_091532] index:6;amount:754;deposits:0;withdrawals:0
// [19920104_091532] index:7;amount:16576;deposits:0;withdrawals:0

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
// [19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
// [19920104_091532] index:2;p_amount:957;deposit:564;amount:1521;nb_deposits:1
// [19920104_091532] index:3;p_amount:432;deposit:2;amount:434;nb_deposits:1
// [19920104_091532] index:4;p_amount:1234;deposit:87;amount:1321;nb_deposits:1
// [19920104_091532] index:5;p_amount:0;deposit:23;amount:23;nb_deposits:1
// [19920104_091532] index:6;p_amount:754;deposit:9;amount:763;nb_deposits:1
// [19920104_091532] index:7;p_amount:16576;deposit:20;amount:16596;nb_deposits:1

// [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
// [19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
// [19920104_091532] index:2;amount:1521;deposits:1;withdrawals:0
// [19920104_091532] index:3;amount:434;deposits:1;withdrawals:0
// [19920104_091532] index:4;amount:1321;deposits:1;withdrawals:0
// [19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
// [19920104_091532] index:6;amount:763;deposits:1;withdrawals:0
// [19920104_091532] index:7;amount:16596;deposits:1;withdrawals:0

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// [19920104_091532] index:2;p_amount:1521;withdrawal:657;amount:864;nb_withdrawals:1
// [19920104_091532] index:3;p_amount:434;withdrawal:4;amount:430;nb_withdrawals:1
// [19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
// [19920104_091532] index:5;p_amount:23;withdrawal:refused
// [19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
// [19920104_091532] index:7;p_amount:16596;withdrawal:7654;amount:8942;nb_withdrawals:1

// [19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
// [19920104_091532] index:1;amount:785;deposits:1;withdrawals:1
// [19920104_091532] index:2;amount:864;deposits:1;withdrawals:1
// [19920104_091532] index:3;amount:430;deposits:1;withdrawals:1
// [19920104_091532] index:4;amount:1245;deposits:1;withdrawals:1
// [19920104_091532] index:5;amount:23;deposits:1;withdrawals:0
// [19920104_091532] index:6;amount:106;deposits:1;withdrawals:1
// [19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1

// [19920104_091532] index:0;amount:47;closed
// [19920104_091532] index:1;amount:785;closed
// [19920104_091532] index:2;amount:864;closed
// [19920104_091532] index:3;amount:430;closed
// [19920104_091532] index:4;amount:1245;closed
// [19920104_091532] index:5;amount:23;closed
// [19920104_091532] index:6;amount:106;closed
// [19920104_091532] index:7;amount:8942;closed