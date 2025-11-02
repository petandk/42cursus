/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:23:16 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/02 17:37:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/DiamondTrap.hpp"

/*
	Default constructor
*/
DiamondTrap::DiamondTrap(void)
	:ClapTrap("None_clap_name")
{
	this->_name = "None";
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 30;
	std::cout <<
	"Default Constructor: DiamondTrap <None> created" <<
	std::endl;
}
/*
	Constructor with name
	Even if the output is the same, the "right" way for multiple inheritance
	is calling ALL the constructors
	DiamondTrap::DiamondTrap(const std::string &name)
		:ClapTrap(name + "_clap_name")
		
*/
DiamondTrap::DiamondTrap(const std::string &name)
	:ClapTrap(name + "_clap_name"), FragTrap(name + "_frag_name"), ScavTrap(name + "_scav_name")
{
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_damage = 30;
	std::cout <<
	"Constructor: DiamondTrap <"<< this->_name <<"> created" <<
	std::endl;
}
/*
	Copy constructor
	Since we're just copying ClapTrap(other) 
	will call the ClapTrap copy constructor
	and copy the values, so not too much to do
*/
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	:ClapTrap(other)
{
	std::cout <<
	"Constructor: DiamondTrap <" << this->_name << "> copied" <<
	std::endl;
}
/*
	Copy assignment
*/
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
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
DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap: Destructor for " << this->_name << " called" << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout	<< "DiamondTrap name: " << this->_name
	<< std::endl
				<< "ClapTrap name:" << ClapTrap::_name
	<< std::endl;
}
