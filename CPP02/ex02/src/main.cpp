/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 13:57:16 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/01 12:37:38 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void) {

	/* MANDATORY TESTS */
	std::cout << "=== MANDATORY TESTS ===" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << '\n' << std::endl;

	/* ADDITIONAL TESTS - INCREMENT/DECREMENT */
	std::cout << "=== INCREMENT/DECREMENT TESTS ===" << std::endl;
	Fixed test1;
	std::cout << "test1 initial\t\t\t\t\t-> " << test1 << std::endl;
	std::cout << "++test1 (pre-increment)\t\t\t\t-> " << ++test1 << std::endl;
	std::cout << "test1 after pre-increment\t\t\t-> " << test1 << std::endl;
	std::cout << "--test1 (pre-decrement)\t\t\t\t-> " << --test1 << std::endl;
	std::cout << "test1 after pre-decrement\t\t\t-> " << test1 << std::endl;
	std::cout << "--test1 (pre-decrement)\t\t\t\t-> " << --test1 << std::endl;
	std::cout << "test1 after pre-decrement\t\t\t-> " << test1 << std::endl;
	std::cout << "test1++ (post-increment, returns old value)\t-> " << test1++ << std::endl;
	std::cout << "test1 after post-increment\t\t\t-> " << test1 << std::endl;
	std::cout << "test1-- (post-decrement, returns old value)\t-> " << test1-- << std::endl;
	std::cout << "test1 after post-decrement\t\t\t-> " << test1 << '\n' << std::endl;

	/* COMPARISON OPERATORS TESTS */
	std::cout << "=== COMPARISON OPERATORS ===" << std::endl;
	Fixed d(10);
	Fixed e(5);
	Fixed f(10);
	
	std::cout << "d = " << d << ", e = " << e << ", f = " << f << std::endl;
	std::cout << "d > e  = " << (d > e ?  "true" : "false") << "\t(expected: true)" << std::endl;
	std::cout << "d < e  = " << (d < e ?  "true" : "false") << "\t(expected: false)" << std::endl;
	std::cout << "d >= f = " << (d >= f ? "true" : "false") << "\t(expected: true)" << std::endl;
	std::cout << "d <= f = " << (d <= f ? "true" : "false") << "\t(expected: true)" << std::endl;
	std::cout << "d == f = " << (d == f ? "true" : "false") << "\t(expected: true)" << std::endl;
	std::cout << "d != e = " << (d != e ? "true" : "false") << "\t(expected: true)" << '\n' << std::endl;

	/* ARITHMETIC OPERATORS TESTS */
	std::cout << "=== ARITHMETIC OPERATORS ===" << std::endl;
	Fixed g(10.5f);
	Fixed h(2.5f);
	
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "g + h = " << (g + h) << "\t\t\t\t(expected: 13)" << std::endl;
	std::cout << "g - h = " << (g - h) << "\t\t\t\t(expected: 8)" << std::endl;
	std::cout << "g * h = " << (g * h) << "\t\t\t\t(expected: 26.25)" << std::endl;
	std::cout << "g / h = " << (g / h) << "\t\t\t\t(expected: 4.2 (it won't be exact))" << std::endl;
	std::cout << "b = Fixed(5.05f) * Fixed(2) = " << b << "\t(expected: 10.1  (it won't be exact))" << '\n' << std::endl;

	/* MIN/MAX FUNCTIONS TESTS */
	std::cout << "=== MIN/MAX FUNCTIONS ===" << std::endl;
	Fixed i(42.42f);
	Fixed j(21.21f);
	
	std::cout << "i = " << i << ", j = " << j << std::endl;
	std::cout << "Fixed::max(i, j) = " << Fixed::max(i, j) << " (expected: 42.42)" << std::endl;
	std::cout << "Fixed::min(i, j) = " << Fixed::min(i, j) << " (expected: 21.21)" << '\n' << std::endl;

	/* CONST MIN/MAX FUNCTIONS TESTS */
	std::cout << "=== CONST MIN/MAX FUNCTIONS ===" << std::endl;
	const Fixed k(100.5f);
	const Fixed l(50.25f);
	
	std::cout << "k = " << k << ", l = " << l << std::endl;
	std::cout << "Fixed::max(k, l) = " << Fixed::max(k, l) << " (expected: 100.5)" << std::endl;
	std::cout << "Fixed::min(k, l) = " << Fixed::min(k, l) << " (expected: 50.25)" << std::endl;

	return 0;
}
