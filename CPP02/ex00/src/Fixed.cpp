/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:07:41 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 14:14:22 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _integer(0) {
	std::cout
	<< GR << "Fixed is created."
	<< std::endl;
}

Fixed::~Fixed {
	std::cout
	<< GR << "Fixed is destroyed."
	<< std::endl;
}