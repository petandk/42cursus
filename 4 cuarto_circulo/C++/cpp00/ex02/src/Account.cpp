/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:48:37 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/15 16:22:50 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

/*
 *   The destructor doesn't really need to destroy anything, just print the same
 *   log message with the "closed" text.
 *   Because if a account "closes" is not operative,
	but the accountIndex is the same,
 *   the money doesn't dissapear...
 */

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

/*  Don't like it, I discovered strftime
void Account::_displayTimestamp(void)
{
	char	buffer[19];

	std::time_t now = std::time(nullptr);
	std::tm *ltm = std::localtime(&now);
	std::cout   << "["
				<< std::setfill('0') << std::setw(4) << 1900 + ltm->tm_year
				<< std::setfill('0') << std::setw(2) << 1 + ltm->tm_mon
				<< std::setfill('0') << std::setw(2) << ltm->tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2) << ltm->tm_hour
				<< std::setfill('0') << std::setw(2) << ltm->tm_min
				<< std::setfill('0') << std::setw(2) << ltm->tm_sec
				<< "]";
}*/
/*
	strftime()
	%Y -> 4 digit year representation (2025)   |   %y
		-> 2 digit year representation (25)
	%d -> day of month with leading zero (01) |  
		%e-> day of month with leading space ( 1)
	%H -> 24h format    |   %I -> 12h format
	buffer needs 19 chars:  Year, month, day, hour, minutes, seconds
	because:                4   +   2  +  2 +   2 +    2   +    2   
		+  4 (for the 4 simbols"[]_ ") + 1 (null terminator)
*/
void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);
    char	buffer[19];
    
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << buffer;
}

int Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

/*
    I can't use _displayTimestamp without modifying the header file (Account.hpp), 
    which I think I am not allowed to do.
    So, copypaste al canto.
*/
void Account::displayAccountsInfos(void)
{
	std::time_t now = std::time(NULL);
	std::tm *ltm = std::localtime(&now);
    char	buffer[19];
    
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << buffer;
    
	std::cout << "accounts:" 
    << Account::getNbAccounts()
    << ";total:" 
    << Account::getTotalAmount() 
    << ";deposits:"
    << Account::getNbDeposits() 
    << ";withdrawals:" 
    << Account::getNbWithdrawals() 
    << std::endl;
}

void    Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
    << ";p_amount:" << checkAmount() 
    << ";deposit:" << deposit;
    _totalNbDeposits++;
    this->_nbDeposits++;
    _totalAmount += deposit;
    this->_amount += deposit;
    std::cout << ";amount:" << checkAmount() 
    << ";nb_deposits:" << this->_nbDeposits 
    << std::endl;
}
bool    Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex 
    << ";p_amount:" << checkAmount() 
    << ";withdrawal:";
    if (withdrawal > this->_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    std::cout << withdrawal;
    _totalNbWithdrawals++;
    this->_nbWithdrawals++;
    _totalAmount -= withdrawal;
    this->_amount -= withdrawal;
    std::cout << ";amount:" << checkAmount() 
    << ";nb_withdrawals:" << this->_nbWithdrawals 
    << std::endl;
    return (true);
}

int	Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this-> _nbWithdrawals
	<< std::endl;
}