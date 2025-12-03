/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:40:26 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/25 14:05:29 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include "utils.hpp"

class	Fixed {
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);							// Default builder
		Fixed(const Fixed& other);				// Copy Builder
		Fixed& operator=(const Fixed& other);	// Copy Assignment operator overload
		~Fixed(void);							// Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
