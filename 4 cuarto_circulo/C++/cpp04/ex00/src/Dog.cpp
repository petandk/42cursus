/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 17:07:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
/*
	Default constructor
*/
Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "Default constructor: Dog successfuly kidnaped" << std::endl;
}

/*
	Copy constructor
*/
Dog::Dog(const Dog &other)
{
	this->_type = other._type;
}

/*
	Copy assignment
*/
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/*
	Destructor
*/
Dog::~Dog(void)
{
	std::cout << "Destructor: Dog successfuly abandoned" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}