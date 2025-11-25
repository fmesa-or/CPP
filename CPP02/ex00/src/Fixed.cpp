/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:07:41 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/25 14:24:39 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/***********************
 * Default Constructor.*
 **********************/
Fixed::Fixed(void) : _fixedPointNumber(0) {
	std::cout << GR << "Default constructor called" << RES << std::endl;
}

/********************
 * Copy Constructor.*
 *******************/
Fixed::Fixed(const Fixed& other) {
	std::cout << YL << "Copy constructor called" << RES << std::endl;
	*this = other;
}

/************************
 * Assignament operator.*
 ***********************/
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << CI IT << "Copy assignment operator called" << RES << std::endl;
	if (this != &other) {
		this->_fixedPointNumber = other.getRawBits();
	}
	return *this;
}

/**************
 * Destructor.*
 *************/
Fixed::~Fixed(void) {
	std::cout << GR << "Destructor called" << RES << std::endl;
}

/***********************************************************
 * Return the @param _fixedPointNumber value as an integer.*
 **********************************************************/
int	Fixed::getRawBits(void) const {
	std::cout << CI IT << "getRawBits member function called" << RES << std::endl;
	return _fixedPointNumber;
}

/***********************************************************************
 * Gives a new value to @param _fixedPointNumber from input @param raw * 
 **********************************************************************/
void	Fixed::setRawBits(int const raw) {
	_fixedPointNumber = raw;
}
