/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:59:50 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/25 13:41:09 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointNumber(0) {
	std::cout << GR << "Default constructor called" << RES << std::endl;
}

Fixed::Fixed(const int num) {
	_fixedPointNumber = num << _fractionalBits;
	std::cout << GR << "Int constructor called" << RES << std::endl;
}

Fixed::Fixed(const float num) {
//	_fixedPointNumber = static_cast<int>(num * (1 << _fractionalBits));
	_fixedPointNumber = roundf(num * (1 << _fractionalBits));
	std::cout << GR << "Float constructor called" << RES << std::endl;
}

Fixed::Fixed(const Fixed& other) : _fixedPointNumber(other._fixedPointNumber) {
	std::cout << YL << "Copy constructor called" << RES << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << CI IT << "Copy assignment operator called" << RES << std::endl;
	if (this != &other) {
		_fixedPointNumber = other._fixedPointNumber;
	}
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << GR << "Destructor called" << RES << std::endl;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointNumber) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointNumber / (1 << _fractionalBits);
}

std::ostream	&operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}
