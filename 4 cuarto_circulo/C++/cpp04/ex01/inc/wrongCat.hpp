/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 18:39:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

#include "wrongAnimal.hpp"
 #include <string>
 #include <iostream>

 class	wrongCat : public wrongAnimal{
	public:
		wrongCat(void);
		wrongCat(const wrongCat &other);
		wrongCat &operator=(const wrongCat &other);
		~wrongCat(void);
		void makeSound(void) const;
 };