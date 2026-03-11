/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:16:19 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 16:48:09 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/**************
 * Construcotr*
 *************/
Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(150) {
	std::cout << IT << "Bureaucrat " << _name
		<< " has been created with a grade value of " << _grade << RES << std::endl;
}

/***************************
 * Char pointer construcotr*
 **************************/
Bureaucrat::Bureaucrat(const char *new_name, unsigned int new_grade) : _name(new_name ? new_name : "undefined") {
	if (new_grade < 1)
		throw GradeTooHighException();
	else if (new_grade > 150)
		throw GradeTooLowException();
	else
	_grade = new_grade;
	std::cout << IT << "Bureaucrat " << _name
		<< " has been created with a grade value of " << _grade << RES << std::endl;
}

/*********************
 * String constructor*
 ********************/
Bureaucrat::Bureaucrat(const std::string &new_name, unsigned int new_grade) : _name(new_name){
	if (new_grade < 1)
		throw GradeTooHighException();
	else if (new_grade > 150)
		throw GradeTooLowException();
	else
	_grade = new_grade;
	std::cout << IT << "Bureaucrat " << _name
		<< " has been created with a grade value of " << _grade << RES << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << IT << "Bureaucrat " << _name
		<< " has been copied with a grade value of " << _grade << RES << std::endl;
}

/*************************************************************************
 * Assignment perator                                                    *
 * (Keep in mind that @param _name is a constant, so it can't be changed)*
 ************************************************************************/
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
		std::cout << IT << "Bureaucrat assignment operator has been called on "
			<< _name << " with grade: " << _grade << RES << std::endl;
	}
	return *this;
}

/*************
 * Destructor*
 ************/
Bureaucrat::~Bureaucrat(void) {
	std::cout << IT << "Destructor called on " << _name << RES << std::endl;
}

//EXCEPTIONS

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Exception: Grade is too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Exception: Grade is too low!";
}

//GETTERS
/***********************
 * Returns @param _name*
 **********************/
const std::string&	Bureaucrat::getName(void) const {
	return (_name);
}

/************************
 * Returns @param _grade*
 ***********************/
unsigned int	Bureaucrat::getGrade(void) const {
	return(_grade);
}

//SETTER
/******************************
 * Changes @param _grade value*
 *****************************/
void	Bureaucrat::setGrade(unsigned int new_grade) {
	if (new_grade < 1)
		throw GradeTooHighException();
	else if (new_grade > 150)
		throw GradeTooLowException();
	else
		_grade = new_grade;
	std::cout << YL IT << _name << " grade changed to " << _grade << RES << std::endl;
}

/********************************************************************
 * Checks if @param _grade is at its limit and substracts one if not*
 *******************************************************************/
void	Bureaucrat::incrementGrade(void) {
	if (_grade <= 1)
		throw GradeTooHighException();
	else
		_grade--;
}

/**************************************************************************
 * If @param n is equal or bigger than the actual @param _grade that means*
 * it will result in something smaller than 1                             *
 *************************************************************************/
void	Bureaucrat::incrementGrade(unsigned int n) {
	if (_grade <= n)
		throw GradeTooHighException();
	else
		_grade -= n;
}

/**************************************************************
 * Checks if @param _grade is at its limit and adds one if not*
 *************************************************************/
void	Bureaucrat::decrementGrade(void) {
	if (_grade >= 150)
		throw GradeTooLowException();
	else
		_grade++;
}

/************************************************************************
 * If adding @param n value to @param _grade results in something bigger*
 * than allowed, it won't let that happen                               *
 ***********************************************************************/
void	Bureaucrat::decrementGrade(unsigned int n) {
	if ((_grade + n) > 150)
		throw GradeTooLowException();
	else
		_grade += n;
}

// OPERATOR
/**************************************************************************
 * Prints a defined message when try to use the full object in a std::cout*
 *************************************************************************/
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
	return os;
}

// METHODS
/*****************************************************************************
 * Calls AForm::beSigned()                                                    *
 *                                                                           *
 * Prints if could signs -> <bureaucrat> signed <form>                       *
 * Prints if couldn't. -> <bureaucrat> couldn’t sign <form> because <reason>.*
 ****************************************************************************/
void	Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << GR
			<< _name << " signed " << form.getName()
			<< RES << std::endl;
	} catch (const std::exception& e) {
		std::cout << IB IT << _name
			<< " couldn't sign " << form.getName() << " because " << e.what() << "."
			<< RES << std::endl;
	}
}

/**********************************
 * Calls AFrom::execute           *
 * If fails sends an Error message*
 *********************************/
void	Bureaucrat::executeForm(const AForm& form) const {
	try {
		form.execute(*this);
		std::cout << GR << _name << "executed" << form.getName() << RES << std::endl;
	}
	catch(const std::exception& e) {
		std::cout << RD << "Error: " << _name << " couldn't execute " << form.getName() 
			<< " because " << e.what() << RES << std::endl;
	}
}
