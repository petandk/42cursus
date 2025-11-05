/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/11/03 19:22:09 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/Animal.hpp"
#include  "../inc/Dog.hpp"
#include  "../inc/Cat.hpp"

#include  "../inc/wrongAnimal.hpp"
#include  "../inc/wrongCat.hpp"

int	main(void)
{
	const	Animal *meta = new Animal();
	const 	Animal *j = new Dog();
	const	Animal *i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	

	std::cout << std::endl
	<< "\033[1;31m=================================================="
	<< std::endl
	<< "\033[33m		now wrong version"
	<< std::endl
	<< "\033[31m==================================================\033[0m"
	<< std::endl << std::endl;

	const wrongAnimal *google = new wrongAnimal();
	const wrongAnimal *p = new wrongCat();

	std::cout << p->getType() << " " << std::endl;
	p->makeSound();
	google->makeSound(); 

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	delete google;
	delete p;

	return (0);
}