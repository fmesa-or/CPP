/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 13:10:26 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/05 14:35:52 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

#include "EasyFind.hpp"

// Try-catch without return 1 to test
int main(void) {
	std::vector<int> vector;
	vector.push_back(4);
	vector.push_back(42);
	vector.push_back(43);
	vector.push_back(1);
	vector.push_back(11);

	try {
		int coincidence = easyFind(vector, 11);
		std::cout << "Coincidence finded: " << coincidence << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	try {
		int coincidence = easyFind(vector, 42);
		std::cout << "Coincidence finded: " << coincidence << std::endl;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}
