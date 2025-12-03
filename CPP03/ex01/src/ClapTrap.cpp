/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:15:51 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/03 13:15:14 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/***********************
 * Default Constructor.*
 **********************/
ClapTrap::ClapTrap(void) : _name("unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GR << "Default constructor called." << RES << std::endl;
}

/**********************
 * String Constructor.*
 *********************/
ClapTrap::ClapTrap(std::string newName) : _name(newName.empty() ? "unnamed" : newName), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GR << "Constructor called.\t" << _name << " is here!" << RES << std::endl;
}

/********************
 * Copy Constructor.*
 *******************/
ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << YL << "Copy constructor called." << RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	}
	std::cout << CI IT << "Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
ClapTrap::~ClapTrap(void) {
	std::cout << GR << "Destructor called." << std::endl;
}

/* METHODS */

/***********************************************************
 * Checks if @param _hitPoints && @param _energyPoints > 0.*
 * If not, returns false.                                  *
 **********************************************************/
bool	ClapTrap::checkState(std::string action, bool flag) {
	if (_hitPoints == 0) {
		std::cout << RD
			<< _name << " is already dead!"
			<< action << " was not possible."
			<< RES << std::endl;
		return false;
	}
	else if (flag == true && _energyPoints == 0) {
		std::cout << RD IT
			<< _name << " has no energy left!"
			<< action << " was not possible."
			<< RES << std::endl;
		return false;
	}
	return true;
}

/*********************************************************
 * Checks state, print attack message and reduces energy.*
 ********************************************************/
void	ClapTrap::attack(const std::string& target) {
	if (!this->checkState("Attack", true))
		return ;
	std::cout << YL
		<< _name << " attacked " << target << ", causing " << _attackDamage << " points of damage!"
		<< RES << std::endl;
	_energyPoints--;
	if (_energyPoints == 0)
		std::cout << IB IT
			<< "Looks like " << _name << " run out of battery."
			<< RES << std::endl;
}

/******************************************************************************
 * Checks state (but not the energy), print attack message and reduces energy.*
 *****************************************************************************/
void	ClapTrap::takeDamage(unsigned int amount) {
	if (!this->checkState("Take damage", false))
		return ;
	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << YL IT
		<< "Oh no!" << _name << " receive " << amount << " points of damage! Ouch! :(\t" 
		<< _hitPoints << " points left!"
		<< RES << std::endl;
	if (_hitPoints == 0)
		std::cout << YL IT
			<< "Aaaaand it's dead."
			<< RES << std::endl;

}

/********************************************************************
 * Checks state, adds hit points, prints message and reduces energy.*
 *******************************************************************/
void	ClapTrap::beRepaired(unsigned int amount) {
	if (!this->checkState("Repair", true))
		return ;
	_hitPoints += amount;
	std::cout << CI
		<< _name << " has repaired " << amount << " point/s to itself.\t"
		<< _hitPoints << " left!"
		<< RES << std::endl;
	_energyPoints--;
	if (_energyPoints == 0)
		std::cout << IB IT
			<< "Looks like " << _name << " run out of battery."
			<< RES << std::endl;
}

/***********************************
 * Getter for @param _attackDamage *
 **********************************/
unsigned int	ClapTrap::getDamage(void) {
	return _attackDamage;
}

/***************************************************
 * Prints message and changes @param _attackDamage *
 **************************************************/
void	ClapTrap::setDamage(unsigned int newDamage) {
	std::cout << PI
		<< _name << " attack damage has change from " << _attackDamage << " to " << newDamage << "."
		<< RES << std::endl;
	_attackDamage = newDamage;
}
