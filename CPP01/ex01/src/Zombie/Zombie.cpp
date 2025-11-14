/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:04:21 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/14 14:05:30 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/***********************************************************************
 * Constructor.                                                        *
 * Initializes a Zombie with the given name and announces its creation.*
 **********************************************************************/
Zombie::Zombie(void) : _name("NULL") {
	std::cout << PI << "\nA zombie is rised from the dead\n" << RES << std::endl;
}

/***************************************************************
 * Destructor.                                                 *
 * Destroys the Zombie object and announces its return to rest.*
 **************************************************************/
Zombie::~Zombie(void) {
	std::cout << YL << "\n" << _name << " got back to eternal rest for the moment...\n" << RES << std::endl;
}
