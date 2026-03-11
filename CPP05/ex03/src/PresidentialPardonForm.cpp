/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:57:59 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 16:49:28 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*******************
 * Constructor void*
 ******************/
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("Undefined") {
	std::cout << IT << getName() << " has been created!" << RES << std::endl;
} 

/*************************
 * Constructor with input*
 ************************/
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << IT << getName() << " has been created!" << RES << std::endl;
} 

/*******************
 * Copy constructor*
 ******************/
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
	std::cout << IT << getName() << " has been created!" << RES << std::endl;
}

/*********************
 * Assignment perator*
 ********************/
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << IT << getName() << " has been assigned!" << RES << std::endl;

	}
	return *this;
}

/*************
 * Destructor*
 ************/
PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << IT << "Destructor called on " << getName() << "with target: " << _target << RES << std::endl;
}

//			MEMBER FUNCTIONS

/*******************************************************
 * Prints a pardon from Zaphond Beeblebrox to <target> *
 ******************************************************/
void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::NotSignedException();

	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << GR IT << _target << " has been pardoned by Zaphod Beeblebrox" << RES << std::endl;
}
