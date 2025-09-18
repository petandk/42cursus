/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/18 18:22:23 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}
	 
void Harl::debug(void)
{
	std::cout << "\033[34m" << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << "\33[0m" << std::endl;
}

void Harl::info(void)
{
	std::cout << "\033[32m" << "[ INFO ]\nI cannot believe adding extra bacon cost more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be askin for more!" << "\33[0m" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "\033[33m" << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month." << "\33[0m" << std::endl;
}

void Harl::error(void)
{
	std::cout << "\033[31m" << "[ ERROR ]\nThis is unacceptable!\n\033[1mI want to speak the manager now." << "\33[0m" << std::endl;
}

void Harl::complain(std::string level)
{
	int i;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++)
	{
		if (level ==  levels[i])
			break;
	}
	switch(i)
	{
		case 0:
			this->debug();
			std::cout << std::endl;
		case 1:
			this->info();
			std::cout << std::endl;
		case 2:
			this->warning();
			std::cout << std::endl;
		case 3:
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cout << "\033[35m[ " << level << " ]\nI don't know what you're talking about, but if it doesn't involve bacon, I'm not interested!\n" << "\033[0m" << std::endl;
			break;
	}
}