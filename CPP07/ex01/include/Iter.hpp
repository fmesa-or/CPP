/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:02:16 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 11:19:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T* array, const size_t length, F function) {
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T, typename F>
void	iter(const T* array, const size_t length, F function) {
	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

#endif
