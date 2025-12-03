/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:05:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/02 14:42:25 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main() {
	
	ClapTrap	eva02("Asuka");
	ClapTrap	evaMP1("Mass Production EVA");

	eva02.setDamage(9);
	evaMP1.setDamage(2);

	ClapTrap	evaMP2(evaMP1);
	ClapTrap	evaMP3(evaMP1);
	ClapTrap	evaMP4(evaMP1);
	ClapTrap	evaMP5(evaMP1);
	ClapTrap	evaMP6(evaMP1);
	ClapTrap	evaMP7(evaMP1);
	ClapTrap	evaMP8(evaMP1);
	ClapTrap	evaMP9(evaMP1);

	eva02.attack("to all Mass Production Evas with pirouettes");
	evaMP1.takeDamage(eva02.getDamage());
	evaMP2.takeDamage(eva02.getDamage());
	evaMP3.takeDamage(eva02.getDamage());
	evaMP4.takeDamage(eva02.getDamage());
	evaMP5.takeDamage(eva02.getDamage());
	evaMP6.takeDamage(eva02.getDamage());
	evaMP7.takeDamage(eva02.getDamage());
	evaMP8.takeDamage(eva02.getDamage());
	evaMP9.takeDamage(eva02.getDamage());

	evaMP1.beRepaired(9);
	evaMP2.beRepaired(9);
	evaMP3.beRepaired(9);
	evaMP4.beRepaired(9);
	evaMP5.beRepaired(9);
	evaMP6.beRepaired(9);
	evaMP7.beRepaired(9);
	evaMP8.beRepaired(9);
	evaMP9.beRepaired(9);

	evaMP1.attack("Asuka");
	eva02.takeDamage(evaMP1.getDamage());

	eva02.beRepaired(1);

	evaMP2.attack("Asuka");
	eva02.takeDamage(evaMP2.getDamage());

	eva02.beRepaired(1);

	evaMP3.attack("Asuka");
	eva02.takeDamage(evaMP3.getDamage());

	eva02.beRepaired(1);

	evaMP4.attack("Asuka");
	eva02.takeDamage(evaMP4.getDamage());

	eva02.beRepaired(1);

	evaMP5.attack("Asuka");
	eva02.takeDamage(evaMP5.getDamage());

	eva02.beRepaired(1);

	evaMP6.attack("Asuka");
	eva02.takeDamage(evaMP6.getDamage());

	eva02.beRepaired(1);

	evaMP7.attack("Asuka");
	eva02.takeDamage(evaMP7.getDamage());

	eva02.beRepaired(1);
	
	evaMP8.attack("Asuka");
	eva02.takeDamage(evaMP8.getDamage());

	eva02.beRepaired(1);
	eva02.beRepaired(1);
	eva02.beRepaired(1);
	eva02.beRepaired(1);

	evaMP9.setDamage(10);
	evaMP9.attack("Asuka");
	eva02.takeDamage(evaMP9.getDamage());

	eva02.beRepaired(1);


	return 0;
}
