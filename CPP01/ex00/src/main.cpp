/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:40:11 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 15:08:05 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombies.hpp"

int	main() {
	// Stack in this scope
	Zombie	zombie("Tontín");
	zombie.announce();

	// Stack, in the scope of randomChump
	randomChump("Tontón");

	// Heap, pointer to use var in any scope
	Zombie*	secondZombie = newZombie("Tontuno");
	secondZombie->announce();

	// Deleted because is dynamic memory
	delete secondZombie;

	return (0);
}