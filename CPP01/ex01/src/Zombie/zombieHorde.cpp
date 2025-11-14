/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:43:28 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/14 14:05:58 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/********************************************************************
 * Uses the @param _name and @param i to say the name and number of *
 * the zombie object and a text with zombie stuff.                  *
 *******************************************************************/
void	Zombie::annouce(int i) {
	std::cout << IT << GR << _name << " nº " << i + 1 << ": BraiiiiiiinnnzzzZ..." << RES << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}

/*****************************************************
 * Allocates N Zombie objects in a single allocation.*
 * Initialize the zombies, giving name to each one.  *
 * Retunr a pointer to the first zombie.             *
 ****************************************************/
Zombie*	zombieHorde(int n, std::string name) {
	Zombie*	horde = new Zombie[n];

	for (int i = 0; i < n; i++)
		horde[i].setName(name);
	return horde;
}