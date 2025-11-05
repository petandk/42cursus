/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 17:21:17 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
/*
	Default constructor
*/
Animal::Animal(void)
{
	this->_type = "Undisclosed";
	std::cout << "Default constructor: Animal created" << std::endl;
}

/*
	Copy constructor
*/
Animal::Animal(const Animal &other)
{
	this->_type = other._type;
}

/*
	Copy assignment
*/
Animal &Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/*
	Destructor
*/
Animal::~Animal(void)
{
	std::cout << "Destructor: Animal sacrified" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "No sound for you" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}