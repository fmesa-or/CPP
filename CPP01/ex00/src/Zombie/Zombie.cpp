/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/21 13:33:28 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/***************
 * Constructor.*
 **************/
Zombie::Zombie(void) {
	std::cout << PI << "\n" << "Unnamed is rised from the dead\n" << RES << std::endl;
}

/************************
 * Constructor for NULL *
 ***********************/
Zombie::Zombie(const char *name) : _name((name ? name : "unnamed")) {
	std::cout << PI << "\n" << _name << " is rised from the dead\n" << RES << std::endl;
}

/***********************************************************************
 * Constructor.                                                        *
 * Initializes a Zombie with the given name and announces its creation.*
 * @param name The name of the zombie.                                 *
 **********************************************************************/
Zombie::Zombie(std::string name) : _name(name) {
	std::cout << PI << "\n" << _name << " is rised from the dead\n" << RES << std::endl;
}

/***************************************************************
 * Destructor.                                                 *
 * Destroys the Zombie object and announces its return to rest.*
 **************************************************************/
Zombie::~Zombie(void) {
	std::cout << YL << "\n" << _name << " got back to eternal rest for the moment...\n" << RES << std::endl;
}

/*****************************************************
 * Gets the name of the Zombie and says zombie stuff.*
 ****************************************************/
void	Zombie::announce() {
	std::cout << IT << GR << _name << ": BraiiiiiiinnnzzzZ..." << RES <<std::endl;
}
