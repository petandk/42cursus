/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 17:00:12 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

#include "Animal.hpp"
 #include <string>
 #include <iostream>

 class	Cat : public Animal{
	public:
		Cat(void);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void);
		void makeSound(void) const;
 };