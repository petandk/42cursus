/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:13:40 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/06 19:30:24 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "IMateriaSource.hpp"

class MateriaSource:public IMateriaSource
{
		public:
			MateriaSource(void);
			MateriaSource(const MateriaSource &other);
			MateriaSource &operator=(const MateriaSource &other);
			virtual	~MateriaSource(void);
	
			virtual	void learnMateria(AMateria *);
			virtual AMateria *createMateria(std::string const &type);
};