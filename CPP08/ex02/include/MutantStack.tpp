/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:32:00 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 18:55:55 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/***************
 * Cosntructor *
 **************/
template<typename T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

/********************
 * Copy Constructor *
 *******************/
template<typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

/************************
 * Assignament operator *
 ***********************/
template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other) {
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

/**************
 * Destructor *
 *************/
template<typename T>
MutantStack<T>::~MutantStack() {}

// METHODS
/*************************************************
 * @param c is inner container from std::stack,  *
 * is a protected attribute that allow access to *
 * beginning and end as iterators                *
 ************************************************/

template<typename T>
typename	MutantStack<T>::iterator	MutantStack<T>::begin() {
	return this->c.begin();
}

template<typename T>
typename	MutantStack<T>::iterator	MutantStack<T>::end() {
	return this->c.end();
}

template<typename T>
typename	MutantStack<T>::const_iterator	MutantStack<T>::begin() const {
	return this->c.begin();
}

template<typename T>
typename	MutantStack<T>::const_iterator	MutantStack<T>::end() const {
	return this->c.end();
}
