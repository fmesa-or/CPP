/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:37:10 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/17 12:54:33 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("NULL") {
	std::cout << "A weapon is constructed\n" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "A weapon is destroyed\n" << std::endl;
}

const std::string&	Weapon::getType(void) {
	return (_type);
}

void	Weapon::setType(std::string newType) {
	_type = newType;
	std::cout << "Weapon type setted to: " << _type << std::endl;
}
