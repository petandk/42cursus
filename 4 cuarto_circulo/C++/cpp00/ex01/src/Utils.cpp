/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  Utils.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:47:24 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/13 18:57:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

/*
	ANSI chars to clear console
	\e		= ESC  (tells the terminal that what comes next is a escape sequence)
	[2J		= "clear screen"
	[x;yH	= does the magic, moves all to position x:y (top left corner is 1,1)
*/
void	clear_console(void)
{
	std::cout << "\e[2J\e[1;1H";
}
/*
	changes option value to uppercase
	numbers and simbols stay unchanged
*/
void	ft_upper(std::string &option)
{
	for (int i = 0; option[i]; i++)
		option[i] = std::toupper(option[i]);
}