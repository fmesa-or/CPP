/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:58:46 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 13:03:25 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/***************
 * Constructor *
 **************/
template <typename T>
Array<T>::Array(void) : _size(0), _array(new T[0]()) {}

/****************************
 * Unsigned int constructor *
 ***************************/
template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[_size]()) {}

/********************
 * Copy constructor *
 *******************/
template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _array(new T[_size]()) {
	for (size_t i = 0; i < _size; ++i) {
		_array[i] = other._array[i];
	}
}

/***********************
 * Assignment operator *
 **********************/
template <typename T>
Array<T>&	Array<T>::operator=(const Array& other) {
	if (this != &other) {
		delete[] _array; // Clears current array to make room to store a a new one.
		_size = other._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; ++i) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}

/********************************************
 * NON CONSTANT Array subscripting operator *
 *******************************************/
template <typename T>
T&	Array<T>::operator[](unsigned int index) {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

/****************************************
 * CONSTANT Array subscripting operator *
 ***************************************/
template <typename T>
const T&	Array<T>::operator[](unsigned int index) const {
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _array[index];
}

template <typename T>
Array<T>::~Array(void) {
	delete[] _array;
}


///////// METHODS ////////

/************************
 * Returns @param _size *
 ***********************/
template <typename T>
unsigned int	Array<T>::size(void) const {
	return _size;
}
