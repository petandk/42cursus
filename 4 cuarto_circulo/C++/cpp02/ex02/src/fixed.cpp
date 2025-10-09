/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:46:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/10/09 20:50:16 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fixed.hpp"

/*
	Default constructor
	initializes fixed-point value to 0
*/
Fixed::Fixed(void)
{
    //std::cout << "Default constructor called" << std::endl;
    this->_value = 0;
}

/*
	Destructor
*/
Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}

/* 
	Copy constructor
	copies the raw fixed-point value 
*/
Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->_value = other._value;
}

/*
	Int constructor
	converts integer to fixed-point by left shift
	(multiply by 256)
	example: n = 3
	then 3 << _fractionalBits = 3 * (2^_fractionalBits) = 3 * 256 = 768
	so our _value stores 768
*/
Fixed::Fixed(const int n)
{
    //std::cout << "Int constructor called" << std::endl;
    this->_value = n << this->_fractionalBits;
}

/*
	Float constructor
	converts float to fixed-point by multiplying by 256 and rounding
	example: n = 3.5
	1 << _fractionalBits is the same as 2^_fractionalBits so 2^8 right now so 256
	then 3.5 * (2^_fractionalBits) = 3.5 * 256 = 896
	then roundf() makes sure we get a int
	so our _value stores 896
*/
Fixed::Fixed(const float n)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_value = roundf(n * (1 << _fractionalBits));
}

/*
	Copy assignment operator
*/
Fixed &Fixed::operator=(const Fixed &other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other._value;
    return (*this);
}

/*
	Comparison operators
*/
bool Fixed::operator>(const Fixed &other) const
{
	return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_value != other._value);
}

/* 
	Arithmetic operators 
*/
Fixed Fixed::operator+(const Fixed &other)
{
	Fixed result;
	result._value = this->_value + other._value;
	return (result);
}
Fixed Fixed::operator-(const Fixed &other)
{
	Fixed result;
	result._value = this->_value - other._value;
	return (result);
}
Fixed Fixed::operator*(const Fixed &other)
{
	Fixed result;
	result._value = (this->_value * other._value) >> this->_fractionalBits;
	return (result);
}
Fixed Fixed::operator/(const Fixed &other)
{
	Fixed result;
		result._value = (this->_value << this->_fractionalBits ) / other._value;
	return (result);
}
/* 
	Pre-increment: ++obj 
*/
Fixed &Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}
/*
	Post-increment: obj++
*/
Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	this->_value++;
	return (copy);
}
/*
	Pre-decrement: --obj
*/
Fixed &Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}
/*
	Post-decrement: obj--
*/
Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	this->_value--;
	return (copy);
}

/*
	Static member functions (min/max)
*/
Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1._value < num2._value)
		return (num1);
	else
		return (num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1._value < num2._value)
		return (num1);
	else
		return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1._value > num2._value)
		return (num1);
	else
		return (num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1._value > num2._value)
		return (num1);
	else
		return (num2);
}



/*
	Insertion operator
	outputs floating-point representation to stream
*/
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

/*
	Returns the raw fixed-point value
*/
int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

/*
	Sets the raw fixed-point value directly
*/
void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

/*
	Converts fixed-point to float by dividing by 2^_fractionalBits
	example: _value = 768
	then 768 / 256.0 = 3.0;
	example2: _value = 896
	then 896 / 256.0 = 3.5;
	then cast to float to ensure we get a floating point number.
*/
float Fixed::toFloat(void) const
{
    return ((float)this->_value / (1 << this->_fractionalBits));
}

/*
	Converts fixed-point to int by right shift
	(divide by 2^_fractionalBits, truncate fractional part)
	example: _value = 768
	then 768 / 256 (>>8) = 3;
	example2: _value = 896
	then 896 / 256 (>>8) = 3; (truncated)
*/
int Fixed::toInt(void) const
{
    return (this->_value >> this->_fractionalBits);
}