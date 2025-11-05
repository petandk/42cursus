/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 13:05:21 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>
#include <iostream>

 class	Cat : public Animal{
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void);
		void makeSound(void) const;
 };