/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:45:56 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 13:00:24 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/***********************
 * Default constructor.*
 **********************/
Cat::Cat(void) : Animal("Cat") {
	_greymass = new Brain();
	std::cout << GR
		<< "Cat: Default consturctor called: " << IT << "Look at this " << this->type
		<< RES << std::endl;
}

/********************
 * Copy constructor.*
 *******************/
Cat::Cat(const Cat& other) : Animal(other) {
	this->type = other.type;
	_greymass = new Brain(*other._greymass);
	std::cout << GR
		<< "Cat: Copy constructor called: " << IT << "Look at this cat! Is very similar to this" << this->type
		<< RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
Cat& Cat::operator=(const Cat& other) {
	if (this != &other) {
		this->type = other.type;
		delete _greymass;
		_greymass = new Brain(*other._greymass);
	}
	std::cout << YL << "Cat: Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
Cat::~Cat(void) {
	delete _greymass;
	std::cout << GR << "Cat: Destructor called. Bye bye " << this->type << RES << std::endl;
}

/*************************
 * Overrides makeSound().*
 ************************/
void	Cat::makeSound(void) const {
		std::cout << CI
			<< type << " makes his sound: " << IT << "MEOW MEOW!!"
			<< RES << std::endl;
}
