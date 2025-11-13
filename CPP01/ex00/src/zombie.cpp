/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 14:46:46 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombies.hpp"

/***********************************************************************
 * Constructor.                                                        *
 * Initializes a Zombie with the given name and announces its creation.*
 * @param name The name of the zombie.                                 *
 **********************************************************************/
Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "\n" << _name << " is rised from the dead\n" << std::endl;
}

/***************************************************************
 * Destructor.                                                 *
 * Destroys the Zombie object and announces its return to rest.*
 **************************************************************/
Zombie::~Zombie(void) {
	std::cout << "\n" << _name << " got back to \"eternal\" rest\n" << std::endl;
}

/*****************************************************
 * Gets the name of the Zombie and says zombie stuff.*
 ****************************************************/
void	Zombie::announce() {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

/**********************************************************
 * Creates a new Zombie on the heap.                      *
 * Allocates a new Zombie dynamically with the given name.*
 * @param name The name of the zombie to create.          *
 * @return A pointer to the newly created Zombie object.  *
 *********************************************************/
Zombie*	newZombie(std::string name) {
	return new Zombie(name);
}

/************************************************************************
 * Creates a temporary zombie on the stack and makes it announce itself.*
 * The zombie is automatically destroyed when the function ends.        *
 * @param name The name of the zombie to create.                        *
 ***********************************************************************/
void	randomChump(std::string name) {
	Zombie	zombie(name);
	zombie.announce();
}
