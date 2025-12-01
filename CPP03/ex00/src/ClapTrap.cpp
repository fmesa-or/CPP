/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:15:51 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/01 13:33:05 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GR << "Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string newName) : _name(newName.empty() ? "unnamed" : newName), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GR << "Constructor called." << _name << " is here!" << RES << std::endl;
}
