/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:33:05 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 16:50:14 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*******************
 * Constructor void*
 ******************/
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Undefined") {
	std::cout << IT << getName() << " has been created!" << RES << std::endl;
} 

/*************************
 * Constructor with input*
 ************************/
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << IT << getName() << " has been created!" << RES << std::endl;
} 

/*******************
 * Copy constructor*
 ******************/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	std::cout << IT << getName() << " has been created!" << RES << std::endl;
}

/*********************
 * Assignment perator*
 ********************/
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
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
RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << IT << "Destructor called on " << getName() << "with target: " << _target << RES << std::endl;
}

//			MEMBER FUNCTIONS

/*************************************************************************
 * Makes some drilling noises and the 50% chances to robotomize <target> *
 ************************************************************************/
void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << YL IT << "<<Drilling noises>>\n" << RES << std::endl;

	if (std::rand() % 2)
		std::cout << GR << _target << " susccesfully robotomized" << RES << std::endl;
	else
		std::cout << RD << _target << " couldn't be robotomized" << RES << std::endl;
}
