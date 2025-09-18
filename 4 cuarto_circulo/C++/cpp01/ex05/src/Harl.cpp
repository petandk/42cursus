/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/18 17:45:28 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}
	 
void Harl::debug(void)
{
	std::cout << "\033[34m" << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << "\33[0m" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[32m" << "INFO: I cannot believe adding extra bacon cost more money. You didn't put enough bacon in my burger! If you did, I wouldn't be askin for more!" << "\33[0m" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[33m" << "WARNING: I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << "\33[0m" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[31m" << "ERROR: This is unacceptable! I want to speak the manager now." << "\33[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void(Harl::*funcPointer[4])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	for (int i = 0; i < 4; i++)
	{
		if (level ==  levels[i])
		{
			(this->*funcPointer[i])();
			return; 
		}
	}
	std::cout << "\033[35m" << level << ": I don't know what you're talking about, but if it doesn't involve bacon, I'm not interested!" << "\033[0m" << std::endl;
}