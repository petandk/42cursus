/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:24:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/10 18:40:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

/*
	Default constructor
*/
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}
/*
	Copy constructor
*/
MateriaSource::MateriaSource(const MateriaSource &other)
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
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
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
MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}
void	MateriaSource::learnMateria(AMateria *materia)
{
	int i = 0;

	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i < 4)
	{
		this->_inventory[i] = materia->clone();
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL && this->_inventory[i]->getType() == type)
		{
			return (this->_inventory[i]->clone());
		}
	}
	return (0);
}