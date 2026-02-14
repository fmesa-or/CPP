/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:51:28 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/14 14:56:34 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {

	Form exam("Examen", 20, 20);
	Bureaucrat example("fmesa", 32);
	example.signForm(exam);
	example.setGrade(15);
	example.signForm(exam);



	Form tooHard("TooHard", 10, 10);
	Bureaucrat low("low", 50);
	low.signForm(tooHard);


	try {
		Form badHigh("BadHigh", 0, 10);
		std::cout << badHigh << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Form Error: " << e.what() << std::endl;
	}

	try {
		Form badLow("BadLow", 10, 151);
		std::cout << badLow << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Form Error: " << e.what() << std::endl;
	}

	return 0;
}
