/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 18:02:23 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 16:45:19 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void testForm(const std::string& formName, const std::string& target) {
	Intern intern;
	AForm* form = intern.makeForm(formName, target);

	if (!form)
		return;

	Bureaucrat example("fmesa", 5);
	form->beSigned(example);
	form->execute(example);

	delete form;
}

int main(void) {
	try {
		srand(std::time(0));
		testForm("PRESIDENTIAL PARDON", "A peasant");
		testForm("ROBOTOMY REQUEST", "Bender");
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}
