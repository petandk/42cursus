/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:58:00 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/14 16:20:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void)
: _name("unnamed"), _signed(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form: Default constructor called." << std::endl;
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
	:_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	_checkGrade(signGrade, "sign");
	_checkGrade(executeGrade, "execute");
	std::cout << "Form: Parametric constructor called." << std::endl;
}

Form::Form(const Form & other)
	:_name(other.getName()),_signed(other.isSigned()), 
	_signGrade(other.requiredSignGrade()), 
	_executeGrade(other.requiredExecuteGrade())
{
	std::cout << "Form: Copy constructor called." << std::endl;
}
/*
	You can only "assign" signed,
	all others are const
*/
Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << "Form: Assignment operator called." << std::endl;
	return *this;
}

Form::~Form(void)
{
	std::cout << "Form: Destructor called." << std::endl;
}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}

int	Form::requiredSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::requiredExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw Form::AlreadySignedForm();	
	if (this->requiredSignGrade() < bureaucrat.getGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

void	Form::_checkGrade(int grade, const std::string &gradeType)
{
	if (grade > 150 || grade < 1)
		std::cout << "Form: " << gradeType << " error. ";
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low!");
}

const char *Form::AlreadySignedForm::what() const throw()
{
	return ("Form: This form was already signed!");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() 
		<< "\nSigned: " << (form.isSigned() ? "yes" : "no")
		<< "\nSign grade required: " << form.requiredSignGrade()
		<< "\nExecute grade required: " << form.requiredExecuteGrade();
	return (out);
}

