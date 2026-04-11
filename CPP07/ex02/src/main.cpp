/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 12:35:02 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/02 13:04:11 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
	Array<int> example(10);
	example[2] = 23;

	try {
		for (size_t i = 0; i < 15; ++i)
			std::cout << example[i] << std::endl;
		
	} catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
