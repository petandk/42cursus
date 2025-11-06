/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:24:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/06 19:31:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"

/*
	Default constructor
*/
MateriaSource::MateriaSource(void)
{
}
/*
	Copy constructor
*/
MateriaSource::MateriaSource(const MateriaSource &other)
{
}
/*
	Copy assignment
*/
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
}
/*
	Destructor
*/
MateriaSource::~MateriaSource(void)
{
}
void	MateriaSource::learnMateria(AMateria *)
{
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
}