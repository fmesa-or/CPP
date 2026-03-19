/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:52:56 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/03/19 16:54:52 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int	main(void) {
	std::srand(std::time(0));
	Base baseIdentifier;

	Base* p = baseIdentifier.generate();
	Base* anotherP = baseIdentifier.generate();

	baseIdentifier.identify(p);
	baseIdentifier.identify(*anotherP);

	delete p;
	delete anotherP;

	return 0;
}
