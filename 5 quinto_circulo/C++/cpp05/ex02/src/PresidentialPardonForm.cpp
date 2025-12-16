/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:35:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/16 18:46:50 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm(void)
	:AForm("Presidential for PRdefault", 25, 5), _target("PRdefault")
{
	std::cout << "Presidential: Default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:AForm("Presidential for " + target, 25, 5), _target(target)
{
	std::cout << "Presidential: Targeted constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	:AForm(other), _target(other.getTarget())
{
	std::cout << "Presidential: Copy constructor called." << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "Presidential: Assign constructor called." << std::endl;
	return (*this);
}


PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Presidential: Destructor called." << std::endl;
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutionRequirements(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}