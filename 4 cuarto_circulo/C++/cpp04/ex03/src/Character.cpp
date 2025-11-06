/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:33:11 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/06 18:51:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"
/*
	Default constructor
*/
Character::Character(void): _name("Anonymous")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
/*
	constructor with name
*/
Character::Character(std::string const &name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
/*
	Copy constructor
*/
Character::Character(const Character &other):_name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}
/*
	Copy assignment
*/
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for(int i = 0; i < 4; i ++)
		{
			if (other._inventory[i] != NULL)
			{
				delete this->_inventory[i];
				this->_inventory[i] = NULL;
			}
		}
		for(int i = 0; i < 4; i ++)
		{
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] == NULL;
		}
	}
	return(*this);
}
/*
	Destructor
*/
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

std::string	const &Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{	
	if (!m)
		return ;
	int	i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i < 4)
		this->_inventory[i] = m;
}
void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}