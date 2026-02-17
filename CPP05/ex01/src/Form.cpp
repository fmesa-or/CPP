/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:10:03 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/17 14:41:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

/**************
 * Construcotr*
 *************/
Form::Form(void) : _name("undefined"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form " << _name
		<< " has been created with a gradeToSign value of " << _gradeToSign 
		<< " a gradeToExecute of " << _gradeToExecute << " and is not signed" << std::endl;
}

/*************************
 * Constructor with input*
 ************************/
Form::Form(std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute) 
: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
		if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	else
			std::cout << "Form " << _name
				<< " has been created with a gradeToSign value of " << _gradeToSign 
				<< " a gradeToExecute of " << _gradeToExecute << " and is not signed" << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
		std::cout << "Form " << _name
			<< " has been copied with a gradeToSign value of " << _gradeToSign 
			<< " a gradeToExecute of " << _gradeToExecute << " and is not signed" << std::endl;
}

/*********************************************************************************
 * Assignment perator                                                            *
 * (Keep in mind that @param _name and grades are constants, so can't be changed)*
 ********************************************************************************/
Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
		std::cout << "Form assignment operator has been called." << std::endl;
	}
	return *this;
}

/*************
 * Destructor*
 ************/
Form::~Form(void) {
	std::cout << "Destructor called on Form : " << _name << std::endl;
}

						// GETTERS
/***********************
 * Returns @param _name*
 **********************/
const std::string&	Form::getName(void) const {
	return (_name);
}

/***************************
 * Returns @param _isSigned*
 **************************/
bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

/******************************
 * Returns @param _gradeToSign*
 *****************************/
unsigned int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

/*********************************
 * Returns @param _gradeToExecute*
 ********************************/
unsigned int	Form::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

						// EXCEPTIONS

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

						// OPERATOR
/**************************************************************************
 * Prints a defined message when try to use the full object in a std::cout*
 *************************************************************************/
std::ostream	&operator<<(std::ostream &os, const Form &form) {
	os << "Form " << form.getName() 
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no") 
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return os;
}

						// MEMBER FUNCTIONS
/**********************************************************
 * Checks if form is already signed.                      *
 * Then checks if the bureaucrat grade is enougth to sign.*
 *********************************************************/
void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned)
		return;

	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();

	_isSigned = true;
}
