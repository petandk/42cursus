/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:20:46 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/04 19:50:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat (void)
	:_name("Bureaucrat Doe"), _grade(1)
{
	std::cout << "Default constructor called." <<std::endl;
}

Bureaucrat::Bureaucrat (const std::string &name)
	:_name(name), _grade(1)
{
	std::cout << "Custom name constructor called." <<std::endl;
}

Bureaucrat::Bureaucrat (int grade)
	:_name("Bureaucrat Doe"), _grade(grade)
{
	_checkGrade(grade);
	std::cout << "Custom grade constructor called." <<std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	:_name(name), _grade(grade)
{
	_checkGrade(grade);
	std::cout << "Parametric constructor called." <<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	:_name(other._name), _grade(other._grade)
{
	_checkGrade(other._grade);
	std::cout << "Copy constructor called." <<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		_checkGrade(other._grade);
		this->_grade = other._grade;
	}

	std::cout << "Assignment operator called." << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

void	Bureaucrat::upgrade(void)
{
	std::cout << "upgrading bureaucrat" << std::endl;
	_checkGrade(this->_grade - 1);
	this->_grade--;

}

void	Bureaucrat::downgrade(void)
{
	std::cout << "downgrading bureaucrat" << std::endl;
	_checkGrade(this->_grade + 1);
	this->_grade++;
}

void Bureaucrat::_checkGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}