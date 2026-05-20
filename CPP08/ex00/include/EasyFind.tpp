/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EasyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:10:53 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/05/20 14:08:05 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EasyFind.hpp"
#include <algorithm>

template <typename T>
int	easyFind(T& container, int num) {
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw std::runtime_error("Occurrence not found");
	return *it;
}



/* VERSION WITHOUT STL
template <typename T>
int	easyFind(T& container, int	num) {
	typename T::iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
		if (*it == num)
			return *it;
	}
	throw std::runtime_error("Ocurrence not found");
}
*/
