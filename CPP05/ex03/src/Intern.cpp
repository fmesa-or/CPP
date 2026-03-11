/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:03:16 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 16:48:22 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/**************
 * Construcotr*
 *************/
Intern::Intern(void) {
	std::cout << IT << "Intern created" << RES << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
Intern::Intern(const Intern& other) {
	(void) other;
	std::cout << IT << "Intern has been copied" << RES << std::endl;
}

/*********************
 * Assignment perator*
 ********************/
Intern&	Intern::operator=(const Intern& other) {
	if (this != &other)
		std::cout << IT << "Intern assignment operator has been called on " << RES << std::endl;
	return *this;
}

/*************
 * Destructor*
 ************/
Intern::~Intern(void) {
	std::cout << IT << "Destructor called on Intern" << RES << std::endl;
}

//			METHODS
/**
 * 
 */
AForm*	Intern::createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

/**
 * 
 */
AForm*	Intern::createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

/**
 * 
 */
AForm*	Intern::createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

/**
 * 
 */
AForm*	Intern::makeForm(std::string formName, std::string targetForm) {
	std::string	formNames[3] = {
		"SHRUBBERY CREATION",
		"ROBOTOMY REQUEST",
		"PRESIDENTIAL PARDON"
	};

	AForm* (Intern::*formCreators[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << PI IT << "Intern creates " << formName << RES << std::endl;
			return (this->*formCreators[i])(targetForm);
		}
	}

	std::cout << RD << "Error: Form name " << formName << " does not exist!" << RES << std::endl;

	return NULL;
}
