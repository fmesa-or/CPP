/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:51:28 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/24 13:48:36 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat example("Pepín", 123);
		std::cout << example.getName() << " has a grade of " << example.getGrade() << std::endl;
		example.setGrade(13);
		example.incrementGrade();
		example.incrementGrade(11);
		std::cout << example << std::endl;
		example.decrementGrade();
		example.decrementGrade(148);
		std::cout << example << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
