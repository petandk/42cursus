/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/05 18:04:17 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Brain.hpp"

#include "../inc/wrongAnimal.hpp"
#include "../inc/wrongCat.hpp"

int	main(void)
{
	Animal *animals[10];
	const Animal *j = new Dog();
	const Animal *k = new Cat();

	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl << std::endl << "Destroy time!" 
	<< std::endl << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
		delete animals[i];

	delete j;
	delete k;

	/*
		Trying to call AAnimal
		should fail to create 	
	*/
/*AAnimal test;*/	
	return (0);
}