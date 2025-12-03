/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:19:49 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/01 12:38:47 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/***********************
 * Default Constructor.*
 **********************/
Fixed::Fixed(void) : _fixedPointNumber(0) {
//	std::cout << GR << "Default constructor called" << RES << std::endl;
}

/********************
 * Copy Constructor.*
 *******************/
Fixed::Fixed(const Fixed& other) : _fixedPointNumber(other._fixedPointNumber) {
//	std::cout << YL << "Copy constructor called" << RES << std::endl;
	*this = other;
}

/*******************
 * Int Constructor.*
 ******************/
Fixed::Fixed(const int num) {
	_fixedPointNumber = num << _fractionalBits;
//	std::cout << GR << "Int constructor called" << RES << std::endl;
}

/*********************
 * Float Constructor.*
 ********************/
Fixed::Fixed(const float num) {
	_fixedPointNumber = roundf(num * (1 << _fractionalBits));
//	std::cout << GR << "Float constructor called" << RES << std::endl;
}

/**************
 * Destructor.*
 *************/
Fixed::~Fixed(void) {
//	std::cout << GR << "Destructor called" << RES << std::endl;
}

/************************
 * Assignament operator.*
 ***********************/
Fixed& Fixed::operator=(const Fixed& other) {
//	std::cout << CI IT << "Copy assignment operator called" << RES << std::endl;
	if (this != &other) {
		_fixedPointNumber = other._fixedPointNumber;
	}
	return *this;
}

/* COMPARISION OPERATORS */

bool	Fixed::operator>(const Fixed& other) const {
	return (_fixedPointNumber > other._fixedPointNumber);
}


bool	Fixed::operator<(const Fixed& other) const {
		return (_fixedPointNumber < other._fixedPointNumber);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (_fixedPointNumber >= other._fixedPointNumber);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (_fixedPointNumber <= other._fixedPointNumber);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (_fixedPointNumber == other._fixedPointNumber);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (_fixedPointNumber != other._fixedPointNumber);
}

/* ARITHMETIC OPERATORS */

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result._fixedPointNumber = _fixedPointNumber + other._fixedPointNumber;
	return result;
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result._fixedPointNumber = _fixedPointNumber - other._fixedPointNumber;
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result._fixedPointNumber = (_fixedPointNumber << _fractionalBits) / other._fixedPointNumber;
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result._fixedPointNumber = (_fixedPointNumber * other._fixedPointNumber) >> _fractionalBits;
	return result;
}

/* INCREMENT/DECREMENT OPERATORS */

Fixed	&Fixed::operator++(void) {
	_fixedPointNumber += 1;
	return *this;
}

Fixed	&Fixed::operator--(void) {
	_fixedPointNumber -= 1;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	result(*this);
	_fixedPointNumber += 1;
	return result;
}

Fixed	Fixed::operator--(int) {
	Fixed	result(*this);
	_fixedPointNumber -= 1;
	return result;
}

/* OVERLOADED MEMBER FUNCTIONS */

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a._fixedPointNumber < b._fixedPointNumber) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a._fixedPointNumber > b._fixedPointNumber) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a._fixedPointNumber < b._fixedPointNumber) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a._fixedPointNumber > b._fixedPointNumber) ? a:b;
}

/* CONVERTERS */
/************************
 * Casts value to Float.*
 ***********************/
float	Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits);
}

/**********************
 * Casts value to Int.*
 *********************/
int	Fixed::toInt(void) const {
	return _fixedPointNumber / (1 << _fractionalBits);
}

/* FUNCTIONS */

/************************************************************************
 * Overloads the insertion operator (<<) for std::ostream compatibility.*
 ************************************************************************/
std::ostream	&operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
