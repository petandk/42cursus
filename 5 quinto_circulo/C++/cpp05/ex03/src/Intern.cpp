/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:31:06 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/18 19:44:36 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern: Default constructor called." << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern: Copy constructor called." << std::endl;
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern: Assignment constructor called." << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern: Destructor called." << std::endl;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &formTarget)
{
	int i;
	std::string names[3] = {"presidential form", "robotomy form", "shrubbery form"};
	for (i = 0; i < 3; i++)
	{
		if (names[i] == formName)
			break;
	}
	switch(i)
	{
		case 0:
		{
			std::cout << "Presidential: Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(formTarget));
		}
		case 1:
		{
			std::cout << "Robotomy: Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(formTarget));
		}
		case 2:
		{
			std::cout << "Shrubbery: Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(formTarget));
		}
		default:
		{
			std::cout << "Intern: " << formName << "doesn't exist." << std::endl;
			return (NULL);
		}
	}
}
