/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:45:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/14 13:02:30 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**********************************************************
 * Creates a new Zombie on the heap.                      *
 * Allocates a new Zombie dynamically with the given name.*
 * @param name The name of the zombie to create.          *
 * @return A pointer to the newly created Zombie object.  *
 *********************************************************/
Zombie*	newZombie(std::string name) {
	return new Zombie(name);
}
