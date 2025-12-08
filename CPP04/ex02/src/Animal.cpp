/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:43:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 14:42:55 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/***********************
 * Default constructor.*
 **********************/
Animal::Animal(void) : type("unidentified animal") {
	std::cout << GR
		<< "Animal: Default consturctor called: " << IT << "Look at this " << type
		<< RES << std::endl;
}

/**********************
 * String constructor.*
 *********************/
Animal::Animal(std::string newType) : type(newType.empty() ? "unidentified animal" : newType) {
	std::cout << GR
		<< "Animal: String constructor called: " << IT << "Look at this " << type
		<< RES << std::endl;
}

/********************
 * Copy constructor.*
 *******************/
Animal::Animal(const Animal& other) {
	type = other.type;
	std::cout << GR
		<< "Animal: Copy constructor called: " << IT "Look at this very similar " << type
		<< RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
		type = other.type;
	std::cout << YL << "Animal: Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
Animal::~Animal(void) {
	std::cout << GR << "Animal: Destructor called. Bye bye " << type << RES << std::endl;
}

/* METHODS */

/***********************
 * Returns @param type *
 **********************/
std::string	Animal::getType(void) const {
	return type;
}

/*************************
 * Makes a generic sound.*
 ************************/
void	Animal::makeSound(void) const {
		std::cout << CI
			<< type << " makes his sound: " << IT << "GENERIC SOUND GENERIC SOUND!!"
			<< RES << std::endl;
}
