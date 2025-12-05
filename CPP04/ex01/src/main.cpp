/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:04:27 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 14:45:45 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void) {
	std::cout << IB << "\n|=== MANDATORY ===|" << RES << std::endl;
	{
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		delete j;
		delete i;
	}
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

/*=====DEEP COPYS=====*/

	std::cout << IB << "\n|=== TEST 2: DEEP COPYS - COPY CONSTRUCTOR =====|" << RES << std::endl;
	{
		Dog	originalDog;
		Dog	copiedDog(originalDog);

		std::cout << "Original Dog address:\t" << &originalDog << std::endl;
		std::cout << "Copied Dog address:\t" << &copiedDog << std::endl;
	}

	std::cout << IB << "\n|=== TEST 3: DEEP COPYS - ASSIGNMENT OP. =====|" << RES << std::endl;
	{
		Dog	dog1;
		Dog	dog2;

		std::cout << "Dog1 address: " << &dog1 << std::endl;
		std::cout << "Dog2 address: " << &dog2 << std::endl;

		dog2 = dog1;

		std::cout << "Dog1 address: " << &dog1 << std::endl;
		std::cout << "Dog2 address: " << &dog2 << std::endl;
	}

	std::cout << IB << "\n|=== TEST 4: DEEP COPYS - CATS =====|" << RES << std::endl;
	{
		Cat	orCat;

		Cat	copCat(orCat);

		std::cout << "Dog1 address: " << &orCat << std::endl;
		std::cout << "Dog2 address: " << &copCat << std::endl;
	}

	std::cout << YL << "\n\n|=== END TESTS ===|" << RES << std::endl;
	return 0;
}
