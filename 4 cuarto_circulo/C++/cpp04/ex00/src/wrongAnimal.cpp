/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 18:39:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wrongAnimal.hpp"
/*
	Default constructor
*/
wrongAnimal::wrongAnimal(void)
{
	this->_type = "Nothing";
	std::cout << "Default constructor: wrongAnimal spawned" << std::endl;
}

/*
	Copy constructor
*/
wrongAnimal::wrongAnimal(const wrongAnimal &other)
{
	this->_type = other._type;
}

/*
	Copy assignment
*/
wrongAnimal &wrongAnimal::operator=(const wrongAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/*
	Destructor
*/
wrongAnimal::~wrongAnimal(void)
{
	std::cout << "Destructor: wrongAnimal ran away" << std::endl;
}

void	wrongAnimal::makeSound(void) const
{
	std::cout << "Insert creepy sound here" << std::endl;
}

std::string	wrongAnimal::getType(void) const
{
	return (this->_type);
}