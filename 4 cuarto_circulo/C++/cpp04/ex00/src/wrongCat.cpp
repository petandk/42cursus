/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 19:20:57 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wrongCat.hpp"
/*
	Default constructor
*/
wrongCat::wrongCat(void)
{
	this->_type = "wrongCat";
	std::cout << "Default constructor: wrongCat came to stay!" << std::endl;
}

/*
	Copy constructor
*/
wrongCat::wrongCat(const wrongCat &other)
{
	this->_type = other._type;
}

/*
	Copy assignment
*/
wrongCat &wrongCat::operator=(const wrongCat &other)
{
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

/*
	Destructor
*/
wrongCat::~wrongCat(void)
{
	std::cout << "Destructor: wrongCat banished" << std::endl;
}

void	wrongCat::makeSound(void) const
{
	std::cout << "QUACK!!!!!" << std::endl;
}