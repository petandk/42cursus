/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:58:00 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/16 18:44:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void)
: _name("unnamed"), _signed(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "AForm: Default constructor called." << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
	:_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	_checkGrade(signGrade, "sign");
	_checkGrade(executeGrade, "execute");
	std::cout << "AForm: Parametric constructor called." << std::endl;
}

AForm::AForm(const AForm & other)
	:_name(other.getName()),_signed(other.isSigned()), 
	_signGrade(other.requiredSignGrade()), 
	_executeGrade(other.requiredExecuteGrade())
{
	std::cout << "AForm: Copy constructor called." << std::endl;
}
/*
	You can only "assign" signed,
	all others are const
*/
AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other._signed;
	std::cout << "AForm: Assignment operator called." << std::endl;
	return *this;
}

AForm::~AForm(void)
{
	std::cout << "AForm: Destructor called." << std::endl;
}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::isSigned(void) const
{
	return (this->_signed);
}

int	AForm::requiredSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::requiredExecuteGrade(void) const
{
	return (this->_executeGrade);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->_signed)
		throw AForm::AlreadySignedForm();	
	if (this->requiredSignGrade() < bureaucrat.getGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

void	AForm::_checkGrade(int grade, const std::string &gradeType)
{
	if (grade > 150 || grade < 1)
		std::cout << "AForm: " << gradeType << " error. ";
	if (grade > 150)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm: Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm: Grade is too low!");
}

const char *AForm::AlreadySignedForm::what() const throw()
{
	return ("AForm: This form was already signed!");
}

const char *AForm::FormNotSigned::what() const throw()
{
	return ("AForm: This form was NOT signed!");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm: " << form.getName() 
		<< "\nSigned: " << (form.isSigned() ? "yes" : "no")
		<< "\nSign grade required: " << form.requiredSignGrade()
		<< "\nExecute grade required: " << form.requiredExecuteGrade();
	return (out);
}

void	AForm::checkExecutionRequirements(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->requiredExecuteGrade())
		throw AForm::GradeTooLowException();
}