/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:14:02 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 13:00:29 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/***********************
 * Default constructor.*
 **********************/
Dog::Dog(void) : Animal("Dog") {
	_greymass = new Brain();
	std::cout << GR
		<< "Dog: Default consturctor called: " << IT << "Look at this " << this->type
		<< RES << std::endl;
}

/********************
 * Copy constructor.*
 *******************/
Dog::Dog(const Dog& other) : Animal(other) {
	this->type = other.type;
	_greymass = new Brain(*other._greymass);
	std::cout << GR
		<< "Dog: Copy constructor called: " << IT "Look at this dog! Is very similar to this" << this->type
		<< RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		this->type = other.type;
		delete _greymass;
		_greymass = new Brain(*other._greymass);
	}
	std::cout << YL << "Dog: Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
Dog::~Dog(void) {
	delete _greymass;
	std::cout << GR << "Dog: Destructor called. Bye bye " << this->type << RES << std::endl;
}

/*************************
 * Overrides makeSound().*
 ************************/
void	Dog::makeSound(void) const {
		std::cout << CI
			<< type << " makes his sound: " << IT << "BARK BARK!!"
			<< RES << std::endl;
}
