/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:35:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/19 19:08:01 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm("Robotomy for ROdefault" , 72, 45), _target("ROdefault")
{
	_initRandom();
	std::cout << "Robotomy: Default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:AForm("Robotomy for " + target, 72, 45), _target(target)
{
	_initRandom();
	std::cout << "Robotomy: Targeted constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	:AForm(other), _target(other.getTarget())
{
	std::cout << "Robotomy: Copy constructor called." << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "Robotomy: Assign constructor called." << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Robotomy: Destructor called." << std::endl;
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

/*
    rand needs to create a seed once during object construction.
    This allows rand() calls in execute() to produce different results
    on each execution while maintaining proper randomization.
*/
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutionRequirements(executor);

	int	noises = 3 + (rand() % 3);

	for (int i = 0; i < noises; i++)
	{
		int sound = rand() % 4;
		switch (sound)
		{
			case 0: std::cout << "Zzzzzzzzz" <<std::endl; break;
			case 1: std::cout << "Brrrrrrrr" <<std::endl; break;
			case 2: std::cout << "Whirrrrrr" <<std::endl; break;
			case 3: std::cout << "Screeeech" <<std::endl; break;
		}
	}
	if (rand() % 2 == 0)
		std::cout << "🤖 " << this->getTarget() << " has been robotomized! 🤖" << std::endl;
	else
		std::cout << "💀 The robotomy failed 💀" << std::endl;
}

void RobotomyRequestForm::_initRandom(void)
{
	static bool	srandInit = false;
	if (!srandInit)
	{
		std::srand(std::time(NULL));
		srandInit = true;
	}
}