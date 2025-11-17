/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:54:50 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/17 13:12:43 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name) {
	_name = name;
	std::cout << _name << " the humanA was created." << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << _name << " the humanA is gone for god." << std::endl;
}

void	HumanA::attack() {
	std::cout << _name << " attacked." << std::endl;
}