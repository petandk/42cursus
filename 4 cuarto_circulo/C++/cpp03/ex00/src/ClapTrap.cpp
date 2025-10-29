/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 20:23:16 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/29 20:17:51 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

/*
	Default constructor 
*/
ClapTrap::ClapTrap(void)
	:_name("Anon"), _health(10), _energy(10), _damage(0)
{
	std::cout <<
	"Default Constructor: Claptrap <Anon> created" <<
	std::endl;
}

/*
	Constructor with name
*/
ClapTrap::ClapTrap(const std::string &name)
	:_name(name), _health(10), _energy(10), _damage(0)
{
	std::cout <<
	"Constructor: Claptrap <" << name <<
	"> created" <<
	std::endl;
}

/*
	Copy constructor
*/
ClapTrap::ClapTrap(const ClapTrap &other)
	:_name(other._name), _health(other._health), _energy(other._energy), _damage(other._damage)
{
	std::cout <<
	"Constructor: Claptrap <" << this->_name <<
	"> copied" <<
	std::endl;
}

/*
	Destructor
*/
ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;

}

/*
	Copy assignment
*/
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
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
	If it has enough energy, and is not dead; 
	it attacks and subtracts 1 energy point.
	it shows a message otherwise.
*/
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ClapTrap: " << this->_name << 
		" attacks " << target << " causing "
		<< this->_damage << " points of damage!" << 
		std::endl;
		this->_energy--;
	}
	else
		std::cout << "This ClapTrap cannot attack!" << std::endl;
}

/*
	since this->_health cannot be negative (is unsigned int)
	I check first if it can be subtracted, if it cannot means that
	the dmg is greater than the health, so I just set health to 0.
	Then if health = 0, I print a death message, else I just
	print a info message.
*/
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health >= amount)
		this->_health -= amount;
	else
		this->_health = 0;
	if (this->_health == 0)
		std::cout << "ClapTrap: " << this->_name << " is dead!" << std::endl;
	else
	{
		std::cout << "ClapTrap: " << this->_name << 
		" lost " << amount << " HP!" << 
		std::endl;
	}
}
/*
	If it has enough energy, and is not dead; 
	it repairs and subtracts 1 energy point.
	it shows a message otherwise.
*/
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy > 0 && this->_health > 0)
	{
		std::cout << "ClapTrap: " << this->_name << 
		" repaired "
		<< amount << " hit points!" << 
		std::endl;
		this->_health += amount;
		this->_energy--;
	}
	else
		std::cout << "This ClapTrap cannot be repaired!" << std::endl;
}