/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 15:02:58 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
/*
	Default constructor
*/
Cat::Cat(void)
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Default constructor: Cat came from heaven" << std::endl;
}

/*
	Copy constructor
*/
Cat::Cat(const Cat &other)
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
}

/*
	Copy assignment
*/
Cat &Cat::operator=(const Cat &other)
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
Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Destructor: Cat forgot you" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Purrrrrrrrrrrrrrrrr" << std::endl;
}