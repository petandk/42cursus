/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:23:16 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/02 17:49:00 by rmanzana         ###   ########.fr       */
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
	std::cout << "ScavTrap: Destructor for " << this->_name << " called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ScavTrap: " << this->_name << 
		" attacks " << target << " causing "
		<< this->_damage << " points of damage, lol!" << 
		std::endl;
		this->_energy--;
	}
	else
		std::cout << "ScavTrap: " << this->_name << " cannot attack, lol!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout  << "ScavTrap: Gatekeeper mode = \033[1;32mtrue\033[0m" << std::endl;
}