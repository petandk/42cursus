/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/04 20:01:29 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << YELLOW << std::endl;
	std::cout << "	✅ Constructors" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Bureaucrat def;
	Bureaucrat name("Ellon");
	Bureaucrat grade(1);
	Bureaucrat full("Muks", 150);

	std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 1" << RESET << std::endl;
	std::cout << def << std::endl;
	std::cout << CYAN << "Expected: Ellon, bureaucrat grade 1" << RESET << std::endl;
	std::cout << name << std::endl;
	std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 1" << RESET << std::endl;
	std::cout << grade << std::endl;
	std::cout << CYAN << "Expected: Muks, bureaucrat grade 150" << RESET << std::endl;
	std::cout << full << std::endl;

	std::cout << YELLOW << std::endl;
	std::cout << "	⚠️  Constructors" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "[TEST] grade -5 Bureaucrat, error expected." << RESET << std::endl;
		Bureaucrat invalid(-5);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] grade 200 Bureaucrat, error expected." << RESET << std::endl;
		Bureaucrat novalid(200);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	©️  Copy Constructor" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat copy(full);
		std::cout << CYAN << "Expected: Muks, bureaucrat grade 150" << RESET << std::endl;
		std::cout << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	🔁 Assignation operator" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Bureaucrat assign("Lenon");
	try
	{
		assign = grade;
		std::cout << CYAN << "Expected: Lenon, bureaucrat grade 1 (name doesn't change)" << RESET << std::endl;
		std::cout << assign << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	♻️  Getters" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "Expected: Lenon" << RESET << std::endl;
		std::cout << assign.getName() << std::endl;
		std::cout << CYAN << "Expected: 1" << RESET << std::endl;
		std::cout << assign.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	⏪ << Operator" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 1" << RESET << std::endl;
		std::cout << def << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	⤴️  Upgrade" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Bureaucrat top(1);
	std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 1" << RESET << std::endl;
	std::cout << top << std::endl;
	try
	{
		top.upgrade();
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	Bureaucrat bottom(150);
	std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 150" << RESET << std::endl;
	std::cout << bottom << std::endl;
	try
	{
		bottom.upgrade();
		bottom.upgrade();
		bottom.upgrade();
		std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 147" << RESET << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}
	
	std::cout << YELLOW << std::endl;
	std::cout << "	⤵️  Downgrade" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat top2(1);
		std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 1" << RESET << std::endl;
		std::cout << top2 << std::endl;
		top2.downgrade();
		top2.downgrade();
		top2.downgrade();
		std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 4" << RESET << std::endl;
		std::cout << top2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	Bureaucrat bottom2(150);
	std::cout << CYAN << "Expected: Bureaucrat Doe, bureaucrat grade 150" << RESET << std::endl;
	std::cout << bottom2 << std::endl;
	try
	{
		bottom2.downgrade();
		std::cout << bottom2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	
	return (0);
}