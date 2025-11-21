/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:54:50 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/21 14:30:32 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/*********************************************************************
 * Creates HumanA object.                                            *
 * @param _name is initiated with @param name in the input.          *
 * @param _weapon is initiated with @param new_weapon as a reference.*
 ********************************************************************/
HumanA::HumanA(std::string name, Weapon& new_weapon) : _name(name), _weapon(new_weapon) {
	std::cout << GR << _name << " the humanA was created." << RES << std::endl;
	std::cout << IB << _name << " is holding " << _weapon.getType() << RES << std::endl;
}

/************************
 * Destroyer for HumanA.*
 ***********************/
HumanA::~HumanA(void) {
	std::cout << PI << _name << " the humanA is gone for god." << RES << std::endl;
}

/******************************************************
 * Uses getType method to get the Weapon @param _type *
 *****************************************************/
void	HumanA::attack() {
	std::cout << RD << _name << " attacks with their " << _weapon.getType() << RES << std::endl;
}
