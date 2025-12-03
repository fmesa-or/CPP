/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 11:25:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 13:04:28 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/***************************************************************
 * Constructor.                                                *
 * Initializes a Harl object and announces its creation.       *
 **************************************************************/
Harl::Harl(void) {
	std::cout << GR
	<< "Harl created"
	<< RES << std::endl;
}

/***********************************************************
 * Destructor.                                             *
 * Destroys the Harl object and announces its destruction. *
 **********************************************************/
Harl::~Harl(void) {
	std::cout << GR
	<< "Harl destroyed"
	<< RES << std::endl;
}

/******************************************************************
 * Outputs a debug level message.                                 *
 * Used for debugging information about bacon preferences.        *
 *****************************************************************/
void	Harl::debug(void) {
	std::cout << YL << IT
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I really do!"
		<< RES << std::endl;
}

/******************************************************************
 * Outputs an info level message.                                 *
 * Used for informational complaints about bacon pricing.         *
 *****************************************************************/
void	Harl::info(void) {
	std::cout << IB << IT
	<< "I cannot believe adding extra bacon costs more money."
	<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
	<< RES << std::endl;
}

/******************************************************************
 * Outputs a warning level message.                               *
 * Used for warning about deserving free bacon.                   *
 *****************************************************************/
void	Harl::warning(void) {
	std::cout << PI << IT
		<< "I think I deserve to have some extra bacon for free."
		<< "I've been coming for years, whereas you started working here just last month."
		<< RES << std::endl;
}

/******************************************************************
 * Outputs an error level message.                                *
 * Used for critical complaints requiring manager intervention.   *
 *****************************************************************/
void	Harl::error(void) {
	std::cout << RD
		<< "This is unacceptable! I want to speak to the manager now."
		<< RES << std::endl;
}

/***************************************************************************
 * Complains at the specified level.                                       *
 * Receives @param level as a string (DEBUG, INFO, WARNING, or ERROR).     *
 *                                                                         *
 * Uses an array of pointers to member functions to call the appropriate  *
 * complaint method based on the level parameter.                          *
 * If the level is not valid, displays an error message.                   *
 **************************************************************************/
void	Harl::complain( std::string level) {
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*functions[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*functions[i])();
			return;
		}
	}

	std::cout << RD
		<< "\nError:\nInvalid level: "<< level << " didn't exist ass an option."
		<< "\nTry DEBUG, INFO, WARNING or ERROR\n"
		<< RES << std::endl;
}
