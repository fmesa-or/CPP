/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:16:49 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/18 18:14:38 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

/*********************************************************************
 * Creates HumanB object.                                            *
 * @param _name is initiated with @param new_name in the input.      *
 * @param _weapon is initiated NULL.                                 *
 ********************************************************************/
HumanB::HumanB(std::string new_name) : _name(new_name), _weapon(NULL) {
	std::cout << GR << _name << " the humanB was created." << RES << std::endl;
}

/************************
 * Destroyer for HumanA.*
 ***********************/
HumanB::~HumanB() {
	std::cout << PI << _name << " the humanB is gone for god." << RES << std::endl;
}

/***********************************************************************
 * @param new_weapon is referenced and added in private @param _weapon *
 **********************************************************************/
void	HumanB::setWeapon(Weapon& new_weapon) {
	_weapon = &new_weapon;
	std::cout << IB << _name << " is holding a " << _weapon->getType() << RES << std::endl;
}

/**********************************************************************************
 * If @param _weapon in't NULL uses getType method to get the Weapon @param _type *
 * If is NULL hits with their bares hands.                                        *
 *********************************************************************************/
void	HumanB::attack() {
	if (_weapon)
		std::cout << RD << _name << " attacks with their " << _weapon->getType() << RES << std::endl;
	else
		std::cout << RD << _name << " attacks with their bare hands." << RES << std::endl;
}
