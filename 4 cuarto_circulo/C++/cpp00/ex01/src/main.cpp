/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:47:24 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/12 20:00:34 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Utils.hpp"

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
	PhoneBook phonebook;

	clear_console();
	print_menu();
	while (std::getline(std::cin, option))
	{
		ft_upper(option);
		if (option == "3" || option == "EXIT")
		{
			clear_console();
			std::cout << "\e[3;5H" << "See you soon!" << std::endl;
			std::getline(std::cin, dummy);
			clear_console();
			return (0);
		}
		else if (option == "2" || option == "SEARCH")
			phonebook.searchContact();
		else if (option == "1" || option == "ADD")
			phonebook.addContact();
		else
			std::cout << "\e[31mInvalid selection\e[0m" << std::endl;
		std::cout << "\nPress \e[31mENTER\e[0m to continue..." << std::endl;
		std::getline(std::cin, dummy);
		clear_console();
		print_menu();
	}
	clear_console();
	return (0);
}
