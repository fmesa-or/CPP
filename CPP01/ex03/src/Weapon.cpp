/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:10 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/18 18:14:55 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/***********************************************************************
 * Constructor.                                                        *
 * Initializes a Weapon recieving a type for the weapon.Then sets Type.*
 **********************************************************************/
Weapon::Weapon(std::string newType) {
	std::cout << YL << "A weapon is constructed. First Type to set: " << newType << RES << std::endl;
	setType(newType);
}

/***********************************************
 * Destructor.                                 *
 * Destroys the Weapon object and announces it.*
 **********************************************/
Weapon::~Weapon(void) {
	std::cout << GR << "A weapon is destroyed. Type:\t" << _type << RES << std::endl;
}

/**********************************************
 * Returns the type of the weapon as a string.*
 *********************************************/
const std::string&	Weapon::getType(void) const {
	return (_type);
}

/***************************************************
 * Sets the type of the weapon with @param newType.*
 **************************************************/
void	Weapon::setType(std::string newType) {
	_type = newType;
	std::cout << CI << "Weapon type setted to:\t" << _type << RES << std::endl;
}
