/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:21:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 11:23:37 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/***********************
 * Default constructor.*
 **********************/
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << GR
		<< "WrongCat: Default consturctor called: " << IT << "Look at this " << this->type
		<< RES << std::endl;
}

/********************
 * Copy constructor.*
 *******************/
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	this->type = other.type;
	std::cout << GR
		<< "WrongCat: Copy constructor called: " << IT "Look at this cat! Is very similira to this" << this->type
		<< RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		this->type = other.type;
	std::cout << YL << "WrongCat: Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
WrongCat::~WrongCat(void) {
	std::cout << GR << "WrongCat: Destructor called. Bye bye " << this->type << RES << std::endl;
}

/*************************
 * Overrides makeSound().*
 ************************/
void	WrongCat::makeSound(void) const {
		std::cout << CI
			<< type << " makes his sound: " << IT << "GOOD EVENING FELLAS!!"
			<< RES << std::endl;
}
