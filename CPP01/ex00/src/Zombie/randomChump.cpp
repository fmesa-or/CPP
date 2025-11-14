/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:46:11 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/14 13:02:33 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/************************************************************************
 * Creates a temporary zombie on the stack and makes it announce itself.*
 * The zombie is automatically destroyed when the function ends.        *
 * @param name The name of the zombie to create.                        *
 ***********************************************************************/
void	randomChump(std::string name) {
	Zombie	zombie(name);
	zombie.announce();
}
