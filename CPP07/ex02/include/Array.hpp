/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:41:25 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 12:46:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

template <typename T>
class Array {
	private:
		unsigned int	_size;
		T*				_array;
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array&		operator=(const Array& other);
		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;
		~Array();

		unsigned int	size(void) const;
};

#include "Array.tpp"

#endif
