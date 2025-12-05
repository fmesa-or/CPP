/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:43:05 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 11:56:29 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/***********************
 * Default constructor.*
 **********************/
Brain::Brain(void) {
	std::cout << PI
		<< "Brain: Default consturctor called: " << IT << "A thought is formed!"
		<< RES << std::endl;
}

/********************
 * Copy constructor.*
 *******************/
Brain::Brain(const Brain& other) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = other.ideas[i];
	}
	std::cout << PI
		<< "Brain: Copy constructor called: " << IT << "They thought the same!"
		<< RES << std::endl;
}

/***********************
 * Assignment operator.*
 **********************/
Brain& Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			ideas[i] = other.ideas[i];
		}
	}
	std::cout << YL << "Brain: Copy assignment operator called" << RES << std::endl;
	return *this;
}

/**************
 * Destructor.*
 *************/
Brain::~Brain(void) {
	std::cout << PI
		<< "Brain: Destructor called." << IT << " Welcome ignorance!"
		<< RES << std::endl;
}
