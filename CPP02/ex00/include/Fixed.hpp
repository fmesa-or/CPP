/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:40:26 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 14:14:13 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "utils.hpp"

class	Fixed {
	private:
		int					_integer;
		static const int	_scinteger = 8;

	public:
		Fixed(void);
		~Fixed(void);

};

#endif