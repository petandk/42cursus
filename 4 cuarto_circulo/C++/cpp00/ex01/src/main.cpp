/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:47:24 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/10 22:21:22 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
	ANSI chars to clear console
	\e		= ESC  (tells the terminal that what comes next is a escape sequence)
	[2J		= "clear screen"
	[x;yH	= does the magic, moves all to position x:y (top left corner is 1,1)
*/
static void	clear_console(void)
{
	std::cout << "\e[2J\e[1;1H";
}
/*
	changes option value to uppercase
	numbers and simbols stay unchanged
*/
static void	ft_upper(std::string &option)
{
	for (int i = 0; option[i]; i++)
		option[i] = std::toupper(option[i]);
}
/*
	formats and prints the menu using the same ANSI "trick"
*/
static void	print_menu(void)
{
	std::cout << "\e[1;3H"
				<< "Please select" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "\e[3;5H"
				<< "1 - ADD" << std::endl;
	std::cout << "\e[4;5H"
				<< "2 - SEARCH" << std::endl;
	std::cout << "\e[5;5H"
				<< "3 - EXIT" << std::endl;
	std::cout << "-----------------" << std::endl;
}

int	main(void)
{
	std::string option;
	std::string dummy;

	clear_console();
	print_menu();
	while (getline(std::cin, option))
	{
		ft_upper(option);
		if (option == "3" || option == "EXIT")
		{
			std::cout << "See you soon!" << std::endl;
			getline(std::cin, dummy);
			clear_console();
			return (0);
		}
		else if (option == "2" || option == "SEARCH")
			std::cout << "SEARCH selected" << std::endl;
		else if (option == "1" || option == "ADD")
			std::cout << "ADD selected" << std::endl;
		else
			std::cout << "\e[31mInvalid selection\e[0m" << std::endl;
		std::cout << "Press \e[31mENTER\e[0m to continue..." << std::endl;

		getline(std::cin, dummy);
		clear_console();
		print_menu();
	}
	clear_console();
	return (0);
}