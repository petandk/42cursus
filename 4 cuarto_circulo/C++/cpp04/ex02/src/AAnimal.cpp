/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 17:44:39 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
/*
	Default constructor
*/
AAnimal::AAnimal(void)
{
	this->_type = "Undisclosed";
	std::cout << "Default constructor: AAnimal created" << std::endl;
}

/*
	Copy constructor
*/
AAnimal::AAnimal(const AAnimal &other)
{
	this->_type = other._type;
}

/*
	Copy assignment
*/
AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/*
	Destructor
*/
AAnimal::~AAnimal(void)
{
	std::cout << "Destructor: AAnimal sacrified" << std::endl;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "No sound for you" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}