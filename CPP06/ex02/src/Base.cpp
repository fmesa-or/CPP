/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:34:20 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/03/19 16:54:17 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

/**************
 * Destructor *
 *************/
Base::~Base(void) {}

/* METHODS */

/*************************************************************************************
 * Randomly instantiates A, B or C class, and returns the isntance as a Base pointer.*
 ************************************************************************************/
Base* Base::generate(void) {
	int	random = std::rand() % 3;

	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}

/********************************************************************
 * Prints the actual type of the object pointed to by p (A, B or C) *
 *******************************************************************/
void	Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << YL << "class A identified" << RES << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << YL << "class B identified" << RES << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << YL << "class C identified" << RES << std::endl;
	else
		std::cout << RD << "Error: Something gonne wrong with your class." << RES << std::endl;
}



/*************************************************************
 * Same as other. Doesn't use a pointer inside this function *
 ************************************************************/
void	Base::identify(Base& p) {
	try
	{
		if (dynamic_cast<A*>(&p))
			std::cout << YL << "class A identified" << RES << std::endl;
		else if (dynamic_cast<B*>(&p))
			std::cout << YL << "class B identified" << RES << std::endl;
		else if (dynamic_cast<C*>(&p))
			std::cout << YL << "class C identified" << RES << std::endl;
		else
			throw std::exception();
	}
	catch(const std::exception& e)
	{
		std::cout << RD << "Error: Something gonne wrong with your class." << RES << std::endl;
		std::cerr << e.what() << '\n';
	}
}
