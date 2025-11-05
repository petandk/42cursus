/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:33:06 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 20:39:31 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
/*
	Default constructor
*/
Ice::Ice(void)
{
	this->type = "ice";
}
/*
	Copy constructor
*/
Ice::Ice(const Ice &other)
{
	this->type = other.type;
}
/*
	Copy assignment
*/
Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}
/*
	Destructor
*/
Ice::~Ice(void)
{
}

AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}