/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:23:16 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/29 21:39:52 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

/*
	Default constructor
*/
ScavTrap::ScavTrap(void)
	:ClapTrap("Nobody")
{
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout <<
	"Default Constructor: ScavTrap <Nobody> created" <<
	std::endl;
}
/*
	Constructor with name
*/
ScavTrap::ScavTrap(const std::string &name)
	:ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 20;
	std::cout <<
	"Constructor: ScavTrap <"<< name <<"> created" <<
	std::endl;
}
/*
	Copy constructor
	Since we're just copying ClapTrap(other) 
	will call the ClapTrap copy constructor
	and copy the values, so not too much to do
*/
ScavTrap::ScavTrap(const ScavTrap &other)
	:ClapTrap(other)
{
	std::cout <<
	"Constructor: ScavTrap <" << this->_name << "> copied" <<
	std::endl;
}
/*
	Copy assignment
*/
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_damage = other._damage;
	}
	return (*this);
}

/*
	Destructor
*/
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called" << std::endl;

}