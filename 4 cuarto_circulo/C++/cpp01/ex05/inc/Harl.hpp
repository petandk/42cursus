/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:11:25 by rmanzana          #+#    #+#             */
/*   Updated: 2025/09/18 16:35:15 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Harl
 {
    public:
		Harl();
		~Harl();
		void	complain(std::string level);
    
    private:
        void	debug(void);
        void	info (void);
        void	warning(void);
		void	error(void);
 };