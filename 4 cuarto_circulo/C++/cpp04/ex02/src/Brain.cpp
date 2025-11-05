/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:50:29 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 12:59:25 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

/*
	Default constructor
*/
Brain::Brain(void)
{
	std::cout << "Default constructor: here's your brain, dont lose it (again)!" << std::endl;
}
/*
	Copy constructor
*/
Brain::Brain(const Brain &other)
{
	*this = other;
}
/*
	Copy assignment
*/
Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = other._ideas[i];
	return(*this);
}
/*
	Destructor
*/
Brain::~Brain(void)
{
	std::cout << "Destructor: your brain is gone!" << std::endl;

}