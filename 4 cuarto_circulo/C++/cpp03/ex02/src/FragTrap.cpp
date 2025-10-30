/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:23:16 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/30 19:30:26 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

/*
		FragTrap is just a copy of ScavTrap just changing a couple
		of things like class name and "special ability"
*/
/*
	Default constructor
*/
FragTrap::FragTrap(void)
	:ClapTrap("Nothing")
{
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout <<
	"Default Constructor: FragTrap <Nothing> created" <<
	std::endl;
}
/*
	Constructor with name
*/
FragTrap::FragTrap(const std::string &name)
	:ClapTrap(name)
{
	this->_health = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout <<
	"Constructor: FragTrap <"<< name <<"> created" <<
	std::endl;
}
/*
	Copy constructor
	Since we're just copying ClapTrap(other) 
	will call the ClapTrap copy constructor
	and copy the values, so not too much to do
*/
FragTrap::FragTrap(const FragTrap &other)
	:ClapTrap(other)
{
	std::cout <<
	"Constructor: FragTrap <" << this->_name << "> copied" <<
	std::endl;
}
/*
	Copy assignment
*/
FragTrap &FragTrap::operator=(const FragTrap &other)
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
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Destructor for " << this->_name << " called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap: can " << this->_name << " get those five? 🫸 💥🫷" << std::endl;
}
