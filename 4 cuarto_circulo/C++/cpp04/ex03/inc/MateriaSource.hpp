/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:13:40 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/10 18:05:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource:public IMateriaSource
{
		public:
			MateriaSource(void);
			MateriaSource(const MateriaSource &other);
			MateriaSource &operator=(const MateriaSource &other);		virtual	~MateriaSource(void);
	
		virtual	void learnMateria(AMateria *materia);
		virtual AMateria *createMateria(std::string const &type);
		
		private:
			AMateria *_inventory[4];
};