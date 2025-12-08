/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:04:27 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/08 22:28:10 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void) {
	std::cout << IB << "\n|=== TEST 1: ANIMALS ARRAY ===|" << RES << std::endl;

	Animal*	zoo[10];

	for (int i = 0; i < 10; ++i){
		if (i < 5)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	for (int i = 0; i < 10; ++i) {
		zoo[i]->makeSound();
	}

	for (int i = 0; i < 10; ++i) {
		delete zoo[i];
	}

	/* This lines can not be compile because Animal is now abtract */
//	Animal	ben;
//	ben.makeSound();

	std::cout << YL << "\n\n|=== END TESTS ===|" << RES << std::endl;
	return 0;
}
