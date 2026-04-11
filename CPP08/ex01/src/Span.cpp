/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:47:24 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 18:08:11 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/***************
 * Constructor *
 **************/
Span::Span(void) : _limits(0) {}

/****************************
 * Unsigned int Constructor *
 ***************************/
Span::Span(unsigned int n) : _limits(n) {
	_vector.reserve(n);
}

/********************
 * Copy Constructor *
 *******************/
Span::Span(const Span& other) : _vector(other._vector), _limits(other._limits) {}

/************************
 * Assignement operator *
 ***********************/
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_vector = other._vector;
		_limits = other._limits;
	}
	return *this;
}

/**************
 * Destructor *
 *************/
Span::~Span(void) {}

////// METHODS //////

/************************************************************
 * Adds a single number to the Span.                        *
 * If there's no room (@param _limits) throws an exception. *
 ***********************************************************/
void	Span::addNumber(int newValue) {
	if (_vector.size() < _limits)
		_vector.push_back(newValue);
	else
		throw std::runtime_error("Value not added: No space left.");
}

/**************************
 * Finds the shortes Span *
 *************************/
int	Span::shortestSpan() {
	if (_vector.empty())
		throw std::runtime_error("No values in Span class.");
	if (_vector.size() == 1)
		throw std::runtime_error("Only 1 value.");
	
		
	std::vector<int>	tmp_vector = _vector;
	std::sort(tmp_vector.begin(), tmp_vector.end());
	int	result = tmp_vector[1] - tmp_vector[0];

	for(size_t i = 1; i < tmp_vector.size() - 1; ++i) {
		if ((tmp_vector[i + 1] - tmp_vector[i]) < result) {
			result = tmp_vector[i + 1] - tmp_vector[i];
		}
	}

	return result;
}

/**************************
 * Finds the longest Span *
 *************************/
int	Span::longestSpan() {
	if (_vector.empty())
		throw std::runtime_error("No values in Span class.");
	if (_vector.size() == 1)
		throw std::runtime_error("Only 1 value.");

	std::vector<int>	tmp_vector = _vector;
	std::sort(tmp_vector.begin(), tmp_vector.end());
	return (tmp_vector[tmp_vector.size() - 1] - tmp_vector[0]);
}
