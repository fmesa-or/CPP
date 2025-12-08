/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:05:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/04 13:10:23 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	// ========================================
	// TEST 1: FragTrap constructors
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 1: FragTrap Constructors           ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "Creating default FragTrap:" << RES << std::endl;
	FragTrap	ft00;
	
	std::cout << YL << "\nCreating FragTrap with name 'Clyde':" << RES << std::endl;
	FragTrap	ft01("Clyde");
	
	std::cout << YL << "\nCreating FragTrap copy from 'Clyde':" << RES << std::endl;
	FragTrap	ft02(ft01);
	
	std::cout << YL << "\nAssigning FragTrap 'Bonnie' to default:" << RES << std::endl;
	ft00 = FragTrap("Bonnie");

	// ========================================
	// TEST 2: FragTrap special ability
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 2: FragTrap highFivesGuys()       ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	ft00.highFivesGuys();
	ft01.highFivesGuys();
	ft02.highFivesGuys();

	// ========================================
	// TEST 3: FragTrap basic actions
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 3: FragTrap Basic Actions         ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "FragTrap attacks:" << RES << std::endl;
	ft01.attack("training dummy");
	ft01.attack("target");
	
	std::cout << YL << "\nFragTrap takes damage:" << RES << std::endl;
	ft01.takeDamage(30);
	ft01.takeDamage(25);
	
	std::cout << YL << "\nFragTrap repairs itself:" << RES << std::endl;
	ft01.beRepaired(20);
	ft01.beRepaired(15);

	// ========================================
	// TEST 4: All three classes comparison
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 4: Three Classes Comparison       ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "Creating one of each type:" << RES << std::endl;
	ClapTrap	clap("ClapBoy");
	ScavTrap	scav("ScavGirl");
	FragTrap	frag("FragMaster");
	
	std::cout << YL << "\nEach attacks a common target:" << RES << std::endl;
	clap.attack("Enemy");
	scav.attack("Enemy");
	frag.attack("Enemy");
	
	std::cout << YL << "\nEach takes 20 damage:" << RES << std::endl;
	clap.takeDamage(20);
	scav.takeDamage(20);
	frag.takeDamage(20);
	
	std::cout << YL << "\nEach repairs 10 HP:" << RES << std::endl;
	clap.beRepaired(10);
	scav.beRepaired(10);
	frag.beRepaired(10);

	// ========================================
	// TEST 5: Special abilities of each class
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 5: Special Abilities               ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "ScavTrap guardGate():" << RES << std::endl;
	scav.guardGate();
	
	std::cout << YL << "\nFragTrap highFivesGuys():" << RES << std::endl;
	frag.highFivesGuys();

	// ========================================
	// TEST 6: Energy depletion test
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 6: Energy Depletion                ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "Creating FragTrap for energy test:" << RES << std::endl;
	FragTrap	energyTest("EnergyTester");
	
	std::cout << YL << "\nPerforming multiple actions to deplete energy:" << RES << std::endl;
	for (int i = 0; i < 15; i++) {
		std::cout << "Action " << i + 1 << ": ";
		if (i % 2 == 0)
			energyTest.attack("dummy");
		else
			energyTest.beRepaired(1);
	}

	// ========================================
	// TEST 7: Death test (0 HP)
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 7: Death Test (0 HP)               ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "Creating FragTrap for death test:" << RES << std::endl;
	FragTrap	deathTest("Mortal");
	
	std::cout << YL << "\nTaking massive damage (more than HP):" << RES << std::endl;
	deathTest.takeDamage(150);
	
	std::cout << YL << "\nAttempting actions while dead:" << RES << std::endl;
	deathTest.attack("ghost");
	deathTest.beRepaired(50);
	deathTest.highFivesGuys();

	// ========================================
	// TEST 8: Combat simulation
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 8: Combat Simulation               ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "Creating combatants:" << RES << std::endl;
	FragTrap	fighter1("Fighter1");
	FragTrap	fighter2("Fighter2");
	
	std::cout << YL << "\nCombat begins!" << RES << std::endl;
	fighter1.attack("Fighter2");
	fighter2.takeDamage(fighter1.getDamage());
	
	fighter2.attack("Fighter1");
	fighter1.takeDamage(fighter2.getDamage());
	
	std::cout << YL << "\nFighters repair:" << RES << std::endl;
	fighter1.beRepaired(15);
	fighter2.beRepaired(15);
	
	std::cout << YL << "\nFighters exchange high fives:" << RES << std::endl;
	fighter1.highFivesGuys();
	fighter2.highFivesGuys();

	// ========================================
	// TEST 9: Inheritance chain test
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    TEST 9: Inheritance Chain               ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	std::cout << YL << "Creating ClapTrap -> ScavTrap -> FragTrap:" << RES << std::endl;
	ClapTrap	baseClap("BaseClap");
	ScavTrap	derivedScav("DerivedScav");
	FragTrap	doubleDerived("DoubleDerived");
	
	std::cout << YL << "\nAttack method override test:" << RES << std::endl;
	std::cout << "ClapTrap attack: ";
	baseClap.attack("target");
	std::cout << "ScavTrap attack: ";
	derivedScav.attack("target");
	std::cout << "FragTrap attack (inherited from ClapTrap): ";
	doubleDerived.attack("target");

	// ========================================
	// DESTRUCTORS
	// ========================================
	std::cout << CI << "\n╔════════════════════════════════════════════╗\n";
	std::cout << "║    Destructors (in reverse order)         ║\n";
	std::cout << "╚════════════════════════════════════════════╝\n" << RES << std::endl;
	
	return 0;
}
