/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/20 19:14:22 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*
	brain: main var;
	*stringPTR: POINTER to that var; just a "paper" with the address written in
	&stringREF: ALIAS to that var; same var, different name
	Use & for address, * to dereference pointer.
*/

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Memory addresses:"
    << "\nstring variable: " << &brain
    << "\nstringPTR: " << stringPTR
    << "\nstringREF: " << &stringREF
    << std::endl;

     std::cout << "Values:"
    << "\nstring variable: " << brain
    << "\nstringPTR: " << *stringPTR
    << "\nstringREF: " << stringREF
    << std::endl;
    return (0);
}