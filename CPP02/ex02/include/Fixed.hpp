/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:58:38 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/28 14:26:06 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

# include "utils.hpp"

class	Fixed {
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const Fixed& other);
		Fixed(const int);
		Fixed(const float);
		~Fixed(void);

		Fixed& operator=(const Fixed& other);

		/* COMPARISION OPERATORS */
		bool				operator>(const Fixed& other) const;
		bool				operator<(const Fixed& other) const;
		bool				operator>=(const Fixed& other) const;
		bool				operator<=(const Fixed& other) const;
		bool				operator==(const Fixed& other) const;
		bool				operator!=(const Fixed& other) const;

		/* ARITHMETIC OPERATORS */
		Fixed				operator+(const Fixed& other) const;
		Fixed				operator-(const Fixed& other) const;
		Fixed				operator*(const Fixed& other) const;
		Fixed				operator/(const Fixed& other) const;

		/* INCREMENT/DECREMENT OPERATORS */
		Fixed				&operator++(void);
		Fixed				&operator--(void);
		Fixed				operator++(int);
		Fixed				operator--(int);

		/* OVERLOADED MEMBER FUNCTIONS */
//		static Fixed		&min(Fixed& a, Fixed& b);
//		static const Fixed	&min(const Fixed& a, const Fixed& b);
//		static Fixed		&max(Fixed& a, Fixed& b);
//		static const Fixed	&max(const Fixed& a, const Fixed& b);

		/* CONVERTERS */
		float				toFloat(void) const;
		int					toInt(void) const;

	};

	std::ostream	&operator<<(std::ostream& out, const Fixed& fixed);

#endif
