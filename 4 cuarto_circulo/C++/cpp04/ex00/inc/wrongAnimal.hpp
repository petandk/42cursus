/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:05:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 18:41:18 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #pragma once

 #include <string>
 #include <iostream>

 class	wrongAnimal{
	public:
		wrongAnimal(void);
		wrongAnimal(const wrongAnimal &other);
		wrongAnimal &operator=(const wrongAnimal &other);
		~wrongAnimal(void);
		
		void		makeSound(void) const;
		std::string	getType(void) const;

	protected:
		std::string	_type;
 };