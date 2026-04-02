/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 10:49:39 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 11:19:56 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void	swap(T& value1, T& value2) {
	T	temp = value1;
	value1 = value2;
	value2 = temp;
}

template <typename T>
T	min(const T& value1, const T& value2) {
	return (value1 < value2) ? value1 : value2;
}

template <typename T>
T	max(const T& value1, const T& value2) {
	return (value1 > value2) ? value1 : value2;
}

#endif
