/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:51:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 19:28:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

/*
	Default constructor
*/
AMateria::AMateria(void)
{
}

/*
	Subject constructor
*/
AMateria::AMateria(std::string const &type)
{
	this->type = type;
}
/*
	Copy constructor
*/
AMateria::AMateria(const AMateria &other)
{
	this->type = other.type;
}
/*
	Copy assignment
*/
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
		this->type = other.type;
	return (*this);
}
/*
	Destructor
*/
AMateria::~AMateria(void)
{
}

std::string const &AMateria::getType(void) const
{
	return (this->type);
}