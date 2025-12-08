/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:28:45 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/04 12:44:36 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/***********************
 * Default constructor.*
 **********************/
ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << GR << "ScavTrap default constructor called." << RES << std::endl;
}

/**********************
 * String constructor.*
 *********************/
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << GR
		<< "Constructor called.\tScavTrap " << _name << " is here!"
		<< RES << std::endl;
}

/*******************
 * Copy construcor.*
 ******************/
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << YL << "ScavTrap copy constructor called." << RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << CI IT << "ScavTrap copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
ScavTrap::~ScavTrap(void) {
	std::cout << GR
		<< "ScavTrap destructor called. Bye bye " << _name << "."
		<< RES << std::endl;
}

/*****************************
 * Overwride attack function.*
 ****************************/
void	ScavTrap::attack(const std::string& target) {
	if (!this->checkState("Attack", true))
		return ;
	std::cout << PI
		<< "ScavTrap " << _name << " fiercely attacks" << target
		<< ", causing " << _attackDamage << " points of damage!"
		<< RES << std::endl;
	_energyPoints--;
	if (_energyPoints == 0)
		std::cout << IB IT
			<< "Looks like " << _name << " run out of battery."
			<< RES << std::endl;}

/**************************
 * Prints special message.*
 *************************/
void	ScavTrap::guardGate(void) {
	std::cout << IB IT
	<< "ScavTrap " << _name << " is now in Gate keeper mode."
	<< RES << std::endl;
}
