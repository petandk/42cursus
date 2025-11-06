/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:01:28 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/06 19:16:35 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character: public ICharacter
{
	public:
		Character(void);
		Character(std::string const &name);
		Character(const Character &other);
		Character &operator=(const Character &other);
		virtual ~Character(void);
		
		virtual std::string const &getName(void) const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);
	
	private:
		std::string _name;
		AMateria *_inventory[4];
};