/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:40:49 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/14 14:06:09 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main() {
	Zombie*	horde;
	int		n = 10;
	std::string	name = "Peztozo";

	if (n > 0) {
		horde = zombieHorde(n, name);

		for (int i = 0; i < n; i++)
			horde->annouce(i);

		delete[] horde;
	}
	return 0;
}