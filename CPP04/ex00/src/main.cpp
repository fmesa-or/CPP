/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:22:07 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 11:34:12 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {

	// MANDATORY
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	// EXTRA
	std::cout << "\n=== Test 1: Destructores (verificar orden correcto) ===" << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << "\n=== Test 2: Constructor de copia de Dog ===" << std::endl;
	Dog originalDog;
	std::cout << "Original Dog type: " << originalDog.getType() << std::endl;
	Dog copiedDog(originalDog);
	std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;
	std::cout << "Original Dog sound: ";
	originalDog.makeSound();
	std::cout << "Copied Dog sound: ";
	copiedDog.makeSound();

	std::cout << "\n=== Test 3: Constructor de copia de Cat ===" << std::endl;
	Cat originalCat;
	std::cout << "Original Cat type: " << originalCat.getType() << std::endl;
	Cat copiedCat(originalCat);
	std::cout << "Copied Cat type: " << copiedCat.getType() << std::endl;
	std::cout << "Original Cat sound: ";
	originalCat.makeSound();
	std::cout << "Copied Cat sound: ";
	copiedCat.makeSound();

	std::cout << "\n=== Test 4: Operador de asignación ===" << std::endl;
	Dog dog1;
	Dog dog2;
	std::cout << "Dog1 sound: ";
	dog1.makeSound();
	std::cout << "Dog2 sound before assignment: ";
	dog2.makeSound();
	dog2 = dog1;
	std::cout << "Dog2 sound after assignment: ";
	dog2.makeSound();

	std::cout << "\n=== Test 5: Array de punteros polimórficos ===" << std::endl;
	const Animal* animals[4];
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	
	for (int idx = 0; idx < 4; idx++) {
		std::cout << "Animal[" << idx << "] type: " << animals[idx]->getType() << " - Sound: ";
		animals[idx]->makeSound();
	}
	
	std::cout << "\n=== Test 6: Eliminando array de animales ===" << std::endl;
	for (int idx = 0; idx < 4; idx++) {
		delete animals[idx];
	}

	std::cout << "\n=== Test 7: Objetos en stack ===" << std::endl;
	{
		Animal baseAnimal;
		Dog stackDog;
		Cat stackCat;
		
		std::cout << "Base Animal type: " << baseAnimal.getType() << " - Sound: ";
		baseAnimal.makeSound();
		std::cout << "Stack Dog type: " << stackDog.getType() << " - Sound: ";
		stackDog.makeSound();
		std::cout << "Stack Cat type: " << stackCat.getType() << " - Sound: ";
		stackCat.makeSound();
		
		std::cout << "Saliendo del scope (destructores automáticos)..." << std::endl;
	}
	std::cout << "Scope finalizado." << std::endl;

	std::cout << "\n=== Test 8: Constructor parametrizado de Animal ===" << std::endl;
	Animal customAnimal("CustomType");
	std::cout << "Custom Animal type: " << customAnimal.getType() << " - Sound: ";
	customAnimal.makeSound();

	std::cout << "\n=== Test 9: WrongAnimal y WrongCat (sin polimorfismo correcto) ===" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	
	std::cout << "WrongAnimal type: " << wrongMeta->getType() << " - Sound: ";
	wrongMeta->makeSound();
	std::cout << "WrongCat type: " << wrongCat->getType() << " - Sound: ";
	wrongCat->makeSound(); // Debería llamar a WrongAnimal::makeSound() en lugar de WrongCat::makeSound()
	
	std::cout << "\n=== Test 10: Comparación con Cat correcto ===" << std::endl;
	const Animal* correctCat = new Cat();
	std::cout << "Cat (correcto) type: " << correctCat->getType() << " - Sound: ";
	correctCat->makeSound(); // Debería llamar correctamente a Cat::makeSound()
	
	std::cout << "\n=== Test 11: Limpieza WrongAnimal y WrongCat ===" << std::endl;
	delete wrongMeta;
	delete wrongCat;
	delete correctCat;

	std::cout << "\n=== Test 12: WrongCat en stack ===" << std::endl;
	{
		WrongAnimal wrongAnimal;
		WrongCat wrongCatStack;
		
		std::cout << "WrongAnimal type: " << wrongAnimal.getType() << " - Sound: ";
		wrongAnimal.makeSound();
		std::cout << "WrongCat type: " << wrongCatStack.getType() << " - Sound: ";
		wrongCatStack.makeSound();
		
		std::cout << "Saliendo del scope (destructores WrongAnimal)..." << std::endl;
	}
	std::cout << "Scope WrongAnimal finalizado." << std::endl;

	std::cout << "\n=== Todos los tests completados ===" << std::endl;

	return 0;
}
