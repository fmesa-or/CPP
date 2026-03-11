/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 14:36:33 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/17 18:32:53 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*******************
 * Constructor void*
 ******************/
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("Undefined") {
	std::cout << getName() << " has been created!" << std::endl;
} 

/*************************
 * Constructor with input*
 ************************/
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << getName() << " has been created!" << std::endl;
} 

/*******************
 * Copy constructor*
 ******************/
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << getName() << " has been created!" << std::endl;
}

/*********************
 * Assignment perator*
 ********************/
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
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
ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "Destructor called on " << getName() << "with target: " << _target << std::endl;
}

//			MEMBER FUNCTIONS

/***********************************************************************************************
 * Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it *
 **********************************************************************************************/
void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (!getIsSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();
	
	std::ofstream file((_target + "_shrubbery").c_str());
	if (!file) {
		std::cout << RD 
			<< "Error: File " << _target << "_shrubbery could not be created." << RES << std::endl;
		return;
	}
	
	file << "                     / / /\n"
		 << "                   /        /  /     //    /\n"
		 << "                /                 /         /  /\n"
		 << "                                /\n"
		 << "                               /                //\n"
		 << "               /          /            /              /\n"
		 << "               /            '/,        /               /\n"
		 << "               /              'b      *\n"
		 << "                /              '$    //                //\n"
		 << "               /    /           $:   /:               /\n"
		 << "             //      /  //      */  @):        /   / /\n"
		 << "                          /     :@,@):   ,/**:'   /\n"
		 << "              /      /,         :@@*: //**'      /   /\n"
		 << "                       '/o/    /:(@'/@*\"'  /\n"
		 << "              /  /       'bq,//:,@@*'   ,*      /  /\n"
		 << "                          ,p$q8,:@)'  /p*'      /\n"
		 << "                   /     '  / '@@Pp@@*'    /  /\n"
		 << "                    /  / //    Y7'.'     /  /\n"
		 << "                              :@):.\n"
		 << "                             .:@:'.\n"
		 << "                           .::(@:.\n";
	file.close();

	std::cout << GR << "File " << _target << "_shrubbery created successfully!" << RES << std::endl;
}
