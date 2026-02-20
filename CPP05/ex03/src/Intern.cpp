/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:03:16 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 12:09:43 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


/**************
 * Construcotr*
 *************/
Intern::Intern(void) {
	std::cout << YL IT << "Intern created" << RES << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
Intern::Intern(const Intern& other) {
	std::cout << YL IT << "Intern has been copied" << RES << std::endl;
}

/*********************
 * Assignment perator*
 ********************/
Intern&	Intern::operator=(const Intern& other) {
	if (this != &other)
		std::cout << YL IT << "Intern assignment operator has been called on " << RES << std::endl;
	return *this;
}

/*************
 * Destructor*
 ************/
Intern::~Intern(void) {
	std::cout << YL IT << "Destructor called on " << RES << std::endl;
}

//			METHODS
/**
 * 
 */
Intern::makeForm(std::string formName, std::string targetForm) {
	// Localizar cual es el formulario
	return (this->/*crear form*/)
}
