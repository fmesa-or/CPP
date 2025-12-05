/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:19:07 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 11:21:35 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/***********************
 * Default constructor.*
 **********************/
WrongAnimal::WrongAnimal(void) : type("unidentified wrong animal") {
	std::cout << GR
		<< "WrongAnimal: Default consturctor called: " << IT << "Look at this " << type
		<< RES << std::endl;
}

/**********************
 * String constructor.*
 *********************/
WrongAnimal::WrongAnimal(std::string newType) : type(newType.empty() ? "unidentified wrong animal" : newType) {
	std::cout << GR
		<< "WrongAnimal: String constructor called: " << IT << "Look at this " << type
		<< RES << std::endl;
}

/********************
 * Copy constructor.*
 *******************/
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	type = other.type;
	std::cout << GR
		<< "WrongAnimal: Copy constructor called: " << IT "Look at this very similira " << type
		<< RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		type = other.type;
	std::cout << YL << "WrongAnimal: Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
WrongAnimal::~WrongAnimal(void) {
	std::cout << GR << "WrongAnimal: Destructor called. Bye bye " << type << RES << std::endl;
}

/* METHODS */

/***********************
 * Returns @param type *
 **********************/
std::string	WrongAnimal::getType(void) const {
	return type;
}

/*************************
 * Makes a generic sound.*
 ************************/
void	WrongAnimal::makeSound(void) const {
		std::cout << CI
			<< type << " makes his sound: " << IT << "WRONG GENERIC SOUND WRONG GENERIC SOUND!!"
			<< RES << std::endl;
}
