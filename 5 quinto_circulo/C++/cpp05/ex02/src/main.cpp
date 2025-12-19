/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/19 19:05:14 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << YELLOW << std::endl;
	std::cout << "	🤵 Bureaucrat Constructors" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Bureaucrat god("God", 1);
	Bureaucrat middle("Random", 50);
	Bureaucrat intern("42Student", 150);

	std::cout << CYAN << "Expected: God, bureaucrat grade 1" << RESET << std::endl;
	std::cout << god << std::endl;
	std::cout << CYAN << "Expected: Random, bureaucrat grade 50" << RESET << std::endl;
	std::cout << middle << std::endl;
	std::cout << CYAN << "Expected: 42Student, bureaucrat grade 150" << RESET << std::endl;
	std::cout << intern << std::endl;

	std::cout << YELLOW << std::endl;
	std::cout << "	📝 Form Constructors" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	ShrubberyCreationForm shrubbery("tree");
	RobotomyRequestForm robotomy("Tamagochi");
	PresidentialPardonForm pardon("Puigdemont");

	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << pardon << std::endl;
	
	std::cout << YELLOW << std::endl;
	std::cout << "	🌲 Shrubbery Tests" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "[TEST] Intern (150) tries to sign (needs 145)" << RESET << std::endl;
		intern.signForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] God (1) signs successfully" << RESET << std::endl;
		god.signForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] Intern (150) tries to execute (needs 137)" << RESET << std::endl;
		intern.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] God (1) executes successfully" << RESET << std::endl;
		god.executeForm(shrubbery);
		std::cout << GREEN << "✓ Check if 'tree_shrubbery' file was created!" << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	🤖 Robotomy Tests" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "[TEST] 42Student (150) tries to sign (needs 72)" << RESET << std::endl;
		intern.signForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] Random (50) signs successfully" << RESET << std::endl;
		middle.signForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] Random (50) tries to execute (needs 45)" << RESET << std::endl;
		middle.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] God (1) executes 5 times (testing 50% randomness)" << RESET << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << CYAN << "Attempt " << i + 1 << ":" << RESET << std::endl;
			god.executeForm(robotomy);
		}
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	👑 Presidential Tests" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "[TEST] Random (50) tries to sign (needs 25)" << RESET << std::endl;
		middle.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] God (1) signs successfully" << RESET << std::endl;
		god.signForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] Random (50) tries to execute (needs 5)" << RESET << std::endl;
		middle.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] God (1) executes successfully" << RESET << std::endl;
		god.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	return (0);
}