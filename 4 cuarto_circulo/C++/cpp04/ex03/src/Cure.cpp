/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:33:06 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 20:40:18 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
/*
	Default constructor
*/
Cure::Cure(void)
{
	this->type = "cure";
}
/*
	Copy constructor
*/
Cure::Cure(const Cure &other)
{
	this->type = other.type;
}
/*
	Copy assignment
*/
Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	return (*this);
}
/*
	Destructor
*/
Cure::~Cure(void)
{
}

AMateria *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}