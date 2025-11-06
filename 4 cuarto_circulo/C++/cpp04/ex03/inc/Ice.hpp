/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:52:33 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/06 19:17:17 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class ICharacter;

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice(void);

		virtual AMateria* clone() const;
		virtual void use(ICharacter &target);
};