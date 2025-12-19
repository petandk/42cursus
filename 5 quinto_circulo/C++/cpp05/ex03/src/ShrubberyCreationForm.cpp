/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:35:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/16 18:48:20 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:AForm("Shrubbery for SHdefault", 145, 137), _target("SHdefault")
{
	std::cout << "Shrubbery: Default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:AForm("Shrubbery for " + target, 145, 137), _target(target)
{
	std::cout << "Shrubbery: Targeted constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	:AForm(other), _target(other.getTarget())
{
	std::cout << "Shrubbery: Copy constructor called." << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	std::cout << "Shrubbery: Assign constructor called." << std::endl;
	return (*this);
}


ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Shrubbery: Destructor called." << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkExecutionRequirements(executor);

	std::ofstream file;
	std::string name = this->getTarget() + "_shrubbery";
	file.open(name.c_str());
	if (!file.is_open())
		throw FileCreationException();
	

	file << "	      *             *" << std::endl;
    file << "                  _/^\\_" << std::endl;
    file << "                 <     >" << std::endl;
    file << "*                 /.-.\\.         *" << std::endl;
    file << "         *        `/&\\`                   *" << std::endl;
    file << "                 ,@.*;@," << std::endl;
    file << "                /_o.I %_\\    *" << std::endl;
    file << "   *           (`'--:o(_@;" << std::endl;
    file << "              /`;--.,__ `')             *" << std::endl;
    file << "             ;@`o % O,*`'`&\\" << std::endl;
    file << "       *    (`'--)_@ ;o %'()\\      *" << std::endl;
    file << "            /`;--._`''--._O'@;" << std::endl;
    file << "           /&*,()~o`;-.,_ `\"\"`)" << std::endl;
    file << "*          /`,@ ;+& () o*`;-';\\" << std::endl;
    file << "          (`\"\"--.,_0 +% @' &()\\" << std::endl;
    file << "          /-.,_    ``''--....-'`)    *" << std::endl;
    file << "     *    /@%;o`:;'--,.__   __.\"\\" << std::endl;
    file << "         ;*,&(); @ % &^;~`\"`o;@();         *" << std::endl;
    file << "         /(); o^~; & ().o@*&`;&%O\\" << std::endl;
    file << "       `\"=\"==\"\"==,,,.,=\"=\"===\"\"`" << std::endl;
    file << "      __.----.(\\ -''#####---...___...-----._" << std::endl;
    file << "    '`         \\)_`\"\"\"\"\"`" << std::endl;
    file << "            .--' ')" << std::endl;
    file << "          o(  )_-\\" << std::endl;
    file << "            `\"\"\"` `" << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return ("Shrubbery: Cannot create/open the file.");
}