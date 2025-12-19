/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/19 19:45:10 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << YELLOW << std::endl;
	std::cout << "	👨‍💼 Intern Constructor" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Intern someRandomIntern;
	AForm *form = NULL;

	std::cout << YELLOW << std::endl;
	std::cout << "	📝 Creating Valid Forms" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	std::cout << CYAN << "[TEST] Creating 'shrubbery form'" << RESET << std::endl;
	form = someRandomIntern.makeForm("shrubbery form", "tree");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = NULL;

	std::cout << std::endl;
	std::cout << CYAN << "[TEST] Creating 'robotomy form'" << RESET << std::endl;
	form = someRandomIntern.makeForm("robotomy form", "Tamagochi");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = NULL;

	std::cout << std::endl;
	std::cout << CYAN << "[TEST] Creating 'presidential form'" << RESET << std::endl;
	form = someRandomIntern.makeForm("presidential form", "Puigdemont");
	if (form)
		std::cout << *form << std::endl;
	delete form;
	form = NULL;

	std::cout << YELLOW << std::endl;
	std::cout << "	⚠️  Invalid Form Test" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	std::cout << CYAN << "[TEST] Creating invalid form (should return NULL)" << RESET << std::endl;
	form = someRandomIntern.makeForm("invalid form name", "target");
	if (form)
	{
		std::cout << RED << "🆘 Error: Form was created when it shouldn't!" << RESET << std::endl;
		delete form;
	}
	else
	{
		std::cout << GREEN << "✅ Correctly returned NULL for invalid form" << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	✨ Executing Intern-created Forms" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Bureaucrat boss("Boss", 1);
	
	std::cout << CYAN << "[TEST] 🌲 Creating and executing shrubbery form" << RESET << std::endl;
	form = someRandomIntern.makeForm("shrubbery form", "garden");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		std::cout << GREEN << "✅ Shrubbery created by Intern works!" << RESET << std::endl;
		delete form;
		form = NULL;
	}

	std::cout << std::endl;
	std::cout << CYAN << "[TEST] 🤖 Creating and executing robotomy form" << RESET << std::endl;
	form = someRandomIntern.makeForm("robotomy form", "R2D2");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		std::cout << GREEN << "✅ Robotomy created by Intern works!" << RESET << std::endl;
		delete form;
		form = NULL;
	}

	std::cout << std::endl;
	std::cout << CYAN << "[TEST] 👑 Creating and executing presidential form" << RESET << std::endl;
	form = someRandomIntern.makeForm("presidential form", "Arthur Dent");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		std::cout << GREEN << "✅ Presidential created by Intern works!" << RESET << std::endl;
		delete form;
		form = NULL;
	}

	std::cout << std::endl;
	return (0);
}