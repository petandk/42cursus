/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/13 16:14:03 by rmanzana         ###   ########.fr       */
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
/*
	the whole point of making a abstract class and making a abstract function
	means that the Abstract class doesn't have to implement that function
	so... no makeSound here!!!

void	AAnimal::makeSound(void) const
{
	std::cout << "No sound for you" << std::endl;
}*/

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}