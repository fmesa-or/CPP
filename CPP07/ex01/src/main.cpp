/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:09:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 11:38:45 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

#include "Iter.hpp"

void	printChar(const char& chr) {
	std::cout << chr << std::flush;
}

void	capitalizeChar(char& chr) {
	if (std::isalpha(chr))
		chr = std::toupper(chr);
}

void	encriptChar(char& chr) {
	size_t	key;
	
	if (std::isalpha(chr)) {
		if (std::isupper(chr))
			key = chr - 64;
		else
			key = chr - 96;

		if (std::isalpha(chr + key))
			chr = chr + key;
		else if (std::isalpha(chr - key))
			chr = chr - key;
		else if (std::isalpha(chr + 1))
			chr = chr + 1;
		else
			chr = chr - 1;
	}
}

int main(void) {
	std::string	myString = "Hello world!";
	iter(&myString[0], myString.size(), printChar);
	std::cout << std::endl;

	iter(&myString[0], myString.size(), capitalizeChar);
	iter(&myString[0], myString.size(), printChar);
	std::cout << std::endl;

	std::string	myString2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	iter(&myString2[0], myString2.size(), printChar);
	std::cout << std::endl;

	iter(&myString2[0], myString2.size(), encriptChar);
	iter(&myString2[0], myString2.size(), printChar);
	std::cout << std::endl;

	std::cout << std::endl;

	// first param: num of elements, second param: value
	const std::vector<char> test(4, 'b');
	// .data() returns pointer to first element inside
	iter(test.data(), test.size(), printChar);

	return 0;
}
