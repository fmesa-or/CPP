/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:05:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/03 13:50:43 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int	main() {
	std::cout << CI << "\n=== Creating ClapTraps ===\n" << RES << std::endl;
	 ClapTrap	ct00;
	 ClapTrap	ct01("Boby");
	 ClapTrap	ct02(ct01);

	 ct00 = ClapTrap ("Miguel");
	 
	 std::cout << CI << "\n=== Creating ScavTraps ===\n" << RES << std::endl;
	 ScavTrap	st00;
	 ScavTrap	st01("Mike Sinaloa");
	 ScavTrap	st02(st01);

	 st00 = ScavTrap("Furiosa");

	 std::cout << CI << "\n=== Testing guardGate ===\n" << RES << std::endl;
	 st00.guardGate();

	 std::cout << CI << "\n=== ClapTrap attack (should print ClapTrap message) ===\n" << RES << std::endl;
	 ct00.attack("Furiosa");
	 st01.takeDamage(ct00.getDamage());
	 
	 std::cout << CI << "\n=== ScavTrap attack (should print ScavTrap message) ===\n" << RES << std::endl;
	 st00.attack("Miguel");
	 ct00.takeDamage(st00.getDamage());

	 std::cout << CI << "\n=== Destructors ===\n" << RES << std::endl;
	 return 0;
	return 0;
}
