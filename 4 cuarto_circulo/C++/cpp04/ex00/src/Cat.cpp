/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 17:07:11 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"
/*
	Default constructor
*/
Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "Default constructor: Cat came from heaven" << std::endl;
}

/*
	Copy constructor
*/
Cat::Cat(const Cat &other)
{
	this->_type = other._type;
}

/*
	Copy assignment
*/
Cat &Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/*
	Destructor
*/
Cat::~Cat(void)
{
	std::cout << "Destructor: Cat forgot you" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Purrrrrrrrrrrrrrrrr" << std::endl;
}