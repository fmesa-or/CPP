/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:32:05 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/03/19 17:00:10 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/**************
 * Constructor*
 *************/
Serializer::Serializer(void) {
	std::cout << "Serializer has been created." << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
Serializer::Serializer(const Serializer& other) {
	(void)other;
}

/**********************
 * Assignment operator*
 *********************/
Serializer& Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

/*************
 * Destructor*
 ************/
Serializer::~Serializer(void) {}


/* METHODS */

/**************************************************************************
 * Takes a pointer and converts it to the unsigned integer type uintptr_t *
 *************************************************************************/
uintptr_t Serializer::serialize(Data* ptr) {
	uintptr_t	raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

/****************************************************************************
 * Takes an unsigned integer parameter and converts it to a pointer to Data *
 ***************************************************************************/
Data* Serializer::deserialize(uintptr_t raw) {
	Data*	ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}
