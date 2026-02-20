/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:33:05 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/17 17:57:31 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*******************
 * Constructor void*
 ******************/
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("Undefined") {
	std::cout << getName() << " has been created!" << std::endl;
} 

/*************************
 * Constructor with input*
 ************************/
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << getName() << " has been created!" << std::endl;
} 

/*******************
 * Copy constructor*
 ******************/
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	std::cout << getName() << " has been created!" << std::endl;
}

/*********************
 * Assignment perator*
 ********************/
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
		std::cout << getName() << " has been assigned!" << std::endl;

	}
	return *this;
}

/*************
 * Destructor*
 ************/
RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "Destructor called on " << getName() << "with target: " << _target << std::endl;
}

//			MEMBER FUNCTIONS

/***********************************************************************************************
 * Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it *
 **********************************************************************************************/
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
