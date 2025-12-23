/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:16:19 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/23 13:14:36 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/**************
 * Construcotr*
 *************/
Bureaucrat::Bureaucrat(void) : _name("undefined"), _grade(150) {
	std::cout << "Bureaucrat " << _name
		<< " has been created with a grade value of " << _grade << std::endl;
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
	std::cout << "Bureaucrat " << _name
		<< " has been created with a grade value of " << _grade << std::endl;
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
	std::cout << "Bureaucrat " << _name
		<< " has been created with a grade value of " << _grade << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat " << _name
		<< " has been copied with a grade value of " << _grade << std::endl;
}

/*************************************************************************
 * Assignment perator                                                    *
 * (Keep in mind that @param _name is a constant, so it can't be changed)*
 ************************************************************************/
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
		std::cout << "Bureaucrat assignment operator has been called on "
			<< _name << " with grade: " << _grade << std::endl;
	}
	return *this;
}

/*************
 * Destructor*
 ************/
Bureaucrat::~Bureaucrat(void) {
	std::cout << "Destructor called on " << _name << std::endl;
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
}

//OPERATOR
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade: " << bureaucrat.getGrade();
	return os;
}
