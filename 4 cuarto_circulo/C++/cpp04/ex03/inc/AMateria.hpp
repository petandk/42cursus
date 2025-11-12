/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:52:33 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/10 18:51:22 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>


class ICharacter;

class AMateria
{
	public:
		AMateria(void);
		AMateria(std::string const &type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		~AMateria(void);

		std::string const &getType(void) const;

		virtual AMateria *clone(void) const = 0;
		virtual void use(ICharacter &target);

	protected:
		std::string	type;
};