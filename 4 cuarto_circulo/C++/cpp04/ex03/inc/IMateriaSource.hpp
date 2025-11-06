/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:54:30 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/06 19:16:47 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual	~IMateriaSource(void) {}
	
		virtual	void learnMateria(AMateria *) = 0;
		virtual AMateria *createMateria(std::string const &type) = 0;
};