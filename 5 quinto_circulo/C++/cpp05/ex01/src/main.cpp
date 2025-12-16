/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/15 19:52:19 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int	main(void)
{
	std::cout << YELLOW << std::endl;
	std::cout << "	📝 Form Constructors" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	Form f1;
	Form f2("tax", 5, 2);

	std::cout << YELLOW << std::endl;
	std::cout << "	⚠️  Form Invalid Constructors" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "[TEST] form sign grade 322, error expected." << RESET << std::endl;
		Form f3("wrong", 322, 3);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] form sign grade -5, error expected." << RESET << std::endl;
		Form f4("wrong", -5, 3);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] form execute grade 500, error expected." << RESET << std::endl;
		Form f5("bad", 1, 500);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}
	
	std::cout << YELLOW << std::endl;
	std::cout << "	©️  Form Copy Constructor" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		Form copy(f2);
		std::cout << CYAN << "Expected: "
		<< "\nForm: tax" 
		<< "\nSigned: no" 
		<< "\nSign grade required: 5"
		<< "\nExecute grade required: 2" << RESET << std::endl;
		std::cout << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}
	std::cout << YELLOW << std::endl;
	std::cout << "	♻️  Form Getters" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "Expected: tax" << RESET << std::endl;
		std::cout << f2.getName() << std::endl;
		std::cout << CYAN << "Expected: no" << RESET << std::endl;
		std::cout << (f2.isSigned() ? "yes" : "no") << std::endl;
		std::cout << CYAN << "Expected: 5" << RESET << std::endl;
		std::cout << f2.requiredSignGrade() << std::endl;
		std::cout << CYAN << "Expected: 2" << RESET << std::endl;
		std::cout << f2.requiredExecuteGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	⏪ Form << Operator" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "Expected: \nForm: tax\nSigned: no\nSign grade required: 5\nExecute grade required: 2" << RESET << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	✍️  Sign Form (Success)" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat boss("Boss", 1);
		Form contract("Contract", 10, 5);
		
		std::cout << CYAN << "[TEST] Boss (grade 1) signs Contract (required grade < 10)" << RESET << std::endl;
		std::cout << CYAN << "Before:\n" << RESET << contract << std::endl;
		boss.signForm(contract);
		std::cout << CYAN << "\nAfter:\n" << RESET << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	❌ Sign Form (Grade too low)" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat intern("Intern", 150);
		Form topSecret("Top Secret", 1, 1);
		
		std::cout << CYAN << "[TEST] Intern (grade 150) tries to sign Top Secret (required grade 1)" << RESET << std::endl;
		std::cout << CYAN << "Before:\n" << RESET << topSecret << std::endl;
		intern.signForm(topSecret);
		std::cout << CYAN << "\nAfter:\n" << RESET << topSecret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	🔁 Sign Form (Already signed)" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		Bureaucrat ceo("CEO", 1);
		Form document("Document", 5, 3);
		
		std::cout << CYAN << "[TEST] CEO signs document twice" << RESET << std::endl;
		ceo.signForm(document);
		std::cout << CYAN << "First signature:\n" << RESET << document << std::endl;
		ceo.signForm(document);
		std::cout << CYAN << "Second signature:\n" << RESET << document << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Error: " << e.what() << RESET << std::endl;
	}

	std::cout << YELLOW << std::endl;
	std::cout << "	🔄 Bonus: Edge cases" << std::endl;
	std::cout << "------------------------------------" << RESET << std::endl << std::endl;

	try
	{
		std::cout << CYAN << "[TEST] Form with grade 1 (highest)" << RESET << std::endl;
		Form vip("VIP Form", 1, 1);
		std::cout << vip << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] Form with grade 150 (lowest)" << RESET << std::endl;
		Form basic("Basic Form", 150, 150);
		std::cout << basic << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	try
	{
		std::cout << CYAN << "[TEST] Bureaucrat at exact required grade" << RESET << std::endl;
		Bureaucrat exact("Exact", 50);
		Form match("Match", 50, 50);
		exact.signForm(match);
		std::cout << match << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << "🆘 Unexpected error: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	return (0);
}