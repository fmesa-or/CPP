/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 14:38:25 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 18:20:07 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try {
		// Test1
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << std::endl;
		// Test2
		std::srand(std::time(0));
		Span	sp2 = Span(10001);
		std::vector<int>	nums;
		for (int i = 0; i < 10001; ++i)
			nums.push_back((std::rand() % 1000000) - 500000);

		sp2.addNumbers(nums.begin(), nums.end());

		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;

		std::cout << std::endl;

		// Test3
		Span	sp3 = Span(1);
		sp3.addNumber(42);
		sp3.shortestSpan();
	}
	catch (const std::exception& ex) {
		std::cout << "Error: Exception: " << ex.what() << std::endl;
	}

	return 0;
}
