/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/01 19:20:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	std::cout << "	✅ Constructors" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	Bureaucrat def;
	Bureaucrat name("Ellon");
	Bureaucrat grade(1);
	Bureaucrat full("Muks", 150);

	std::cout << "Expected: Bureaucrat Doe, grade 1" << std::endl;
	std::cout << def << std::endl;
	std::cout << "Expected: Ellon, grade 1" << std::endl;
	std::cout << name << std::endl;
	std::cout << "Expected: Bureaucrat Doe, grade 1" << std::endl;
	std::cout << grade << std::endl;
	std::cout << "Expected: Muks, grade 150" << std::endl;
	std::cout << full << std::endl;

	std::cout << "	⚠️ Constructors" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat invalid(-5);
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat novalid(200);
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Error: " << e.what() << std::endl;
	}

	std::cout << "	©️ Copy Constructor" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat copy(full);
		std::cout << "Expected: Muks, grade 150" << std::endl;
		std::cout << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "	🔁 Assignation operator" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	Bureaucrat assign("Lenon");
	try
	{
		assign = grade;
		std::cout << "Expected: Lenon, grade 1 (name doesn't change)" << std::endl;
		std::cout << assign << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "	♻️ Getters" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	try
	{
		std::cout << "Expected: Lenon" << std::endl;
		std::cout << assign.getName() << std::endl;
		std::cout << "Expected: 1" << std::endl;
		std::cout << assign.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "	⏪ << operator" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	try
	{
		std::cout << def << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Unexpected error: " << e.what() << std::endl;
	}

	std::cout << "	⤴️ upgrade" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	Bureaucrat top(1);
	std::cout << "Expected: Bureaucrat Doe, grade 1" << std::endl;
	std::cout << top << std::endl;
	try
	{
		top.upgrade();
		std::cout << top << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Error: " << e.what() << std::endl;
	}

	Bureaucrat bottom(150);
	std::cout << "Expected: Bureaucrat Doe, grade 150" << std::endl;
	std::cout << bottom << std::endl;
	try
	{
		bottom.upgrade();
		bottom.upgrade();
		bottom.upgrade();
		std::cout << "Expected: Bureaucrat Doe, grade 147" << std::endl;
		std::cout << bottom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Unexpected error: " << e.what() << std::endl;
	}
	
	std::cout << "	⤵️ downgrade" << std::endl;
	std::cout << "------------------" << std::endl << std::endl;

	try
	{
		Bureaucrat top2(1);
		std::cout << "Expected: Bureaucrat Doe, grade 1" << std::endl;
		std::cout << top2 << std::endl;
		top2.downgrade();
		top2.downgrade();
		top2.downgrade();
		std::cout << "Expected: Bureaucrat Doe, grade 4" << std::endl;
		std::cout << top2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Unexpected error: " << e.what() << std::endl;
	}

	Bureaucrat bottom2(150);
	std::cout << "Expected: Bureaucrat Doe, grade 150" << std::endl;
	std::cout << bottom2 << std::endl;
	try
	{
		bottom2.downgrade();
		std::cout << bottom2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "🆘 Error: " << e.what() << std::endl;
	}

	return (0);
}