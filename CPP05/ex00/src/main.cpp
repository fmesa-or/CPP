/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:51:28 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/23 13:14:59 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat example("Pepín", 123);
		std::cout << example.getName() << " has a grade of " << example.getGrade() << std::endl;
		example.setGrade(13);
		example.setGrade(0);
		std::cout << example << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
