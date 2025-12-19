/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:20:46 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/18 16:21:34 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
	std::cout << "Copy constructor called." <<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	std::cout << "Assignment operator called." << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor called." << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\033[32m✅ " << this->_name << " signed " << form.getName() << "\033[0m" << std::endl << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "\033[1;31m🆘 " << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl << std::endl;
	}
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

void	Bureaucrat::_checkGrade(int grade)
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

void	Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << "\033[32m✅ " << this->_name << " executed " << form.getName() << "\033[0m" << std::endl;

	}
	catch(const std::exception &e)
	{
        std::cout << "\033[1;31m🆘 " << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}