/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:10:53 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 14:27:48 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"

template <typename T>
int	easyFind(T& container, int	num) {
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == num)
			return *it;
	}
	throw std::runtime_error("Ocurrence not found");
}
