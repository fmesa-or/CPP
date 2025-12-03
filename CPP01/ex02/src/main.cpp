/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 11:43:21 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 12:18:24 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;

	// Memories address print
	std::cout << "The memory address of the string variable:\t" << &brain << std::endl;
	std::cout << "The memory address held by stringPTR:\t\t" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:\t\t" << &stringREF <<std::endl;

	// Values print
	std::cout << "Value of string:\t\t\t\t" << brain << std::endl;
	std::cout << "Value pointed by stringPTR:\t\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF:\t\t\t" << stringREF << std::endl;
	return 0;
}
