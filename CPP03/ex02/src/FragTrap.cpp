/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:28:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/04 13:14:13 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/***********************
 * Default constructor.*
 **********************/
FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << GR << "FragTrap default constructor called." << RES << std::endl;
}

/**********************
 * String constructor.*
 *********************/
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << GR
		<< "Constructor called.\tFragTrap " << _name << " is here!"
		<< RES << std::endl;
}

/*******************
 * Copy construcor.*
 ******************/
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << YL << "FragTrap copy constructor called." << RES << std::endl;

}

/***********************
 * Assignment operator.*
 **********************/
FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << CI IT << "FragTrap copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
FragTrap::~FragTrap(void) {
	std::cout << GR
		<< "FragTrap destructor called. Bye bye " << _name << "."
		<< RES << std::endl;
}

/* METHODS */

/******************************
 * Prints a high five message.*
 *****************************/
void	FragTrap::highFivesGuys(void) {
	std::cout << YL << _name << ": " << IT << "Give me a high five!" << RES << std::endl;
}
