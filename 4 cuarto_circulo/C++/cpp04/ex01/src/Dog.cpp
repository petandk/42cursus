/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 15:02:40 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"
/*
	Default constructor
*/
Dog::Dog(void)
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Default constructor: Dog successfuly kidnaped" << std::endl;
}

/*
	Copy constructor
*/
Dog::Dog(const Dog &other)
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

/*
	Copy assignment
*/
Dog &Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

/*
	Destructor
*/
Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Destructor: Dog successfuly abandoned" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}