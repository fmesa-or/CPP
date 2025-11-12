/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:59:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/12 13:03:05 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
In your code, the phonebook must be instantiated as an instance of the PhoneBook
class. Same thing for the contacts. Each one of them must be instantiated as an instance
of the Contact class. You’re free to design the classes as you like but keep in mind that
anything that will always be used inside a class is private, and that anything that can be
used outside a class is public.
*/


//At start-up phonebook is empty
//Prompted to enter one of three commands: ADD, SEARCH or EXIT.


//Ignore any other input.
#include "PhoneBook.hpp"

int	main() {
	size_t	option = 0;
	PhoneBook myNewPhoneBook;

	std::cout << YL << "\t\tPhoneBook OPEN" << RES << std::endl;
	while (option != EXIT) {
		display_options();
		option = get_option();
		switch (option) {
			case ADD:
				myNewPhoneBook.addContact();
				break;
			case SEARCH:
				myNewPhoneBook.searchContact();
				break;
			case EXIT:
				std::cout << GR << "\n\tSayonara Baby!" << RES << std::endl;
				break;
			default:
				error_msg("Invalid input.");
		}
	}
	return (0);
}
