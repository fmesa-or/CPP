/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:38:45 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 18:20:14 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>


class Span
{
private:
	std::vector<int>	_vector;
	size_t				_limits;

public:
	Span(void);
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span(void);

	void	addNumber(int newValue);

	int	shortestSpan();

	int	longestSpan();

	/************************************************************
	 * Adds multiple numbers to the Span.                       *
	 * If there's no room (@param _limits) throws an exception. *
	 ***********************************************************/
	template<typename T>
	void	addNumbers(T first, T last) {
		while (first != last) {
			addNumber(*first);
			++first;
		}
	}
};


#endif
