/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 16:56:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

 #include "Animal.hpp"
 #include <string>
 #include <iostream>

 class	Dog : public Animal{
	public:
		Dog(void);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void);
		void	makeSound(void) const;
 };