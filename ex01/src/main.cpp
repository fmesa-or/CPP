/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:59:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/10 15:04:23 by fmesa-or         ###   ########.fr       */
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

/*ADD
	Prompt to input the info of a new contact one field at a time. Once all the fields have been completed add it ti tge phonebook*
*/

/*SEARCH
	Display the saved contacts as a list of 4 columns: index, first name, last name and nickname
	Each column has 10 chars wide. Separeted with a pipe. Right-aligned text. If longer than 10 chars, truncate it and last char is a dot ('.').
	Then, prompt the user again for the index of the entry to display. If the index
is out of range or wrong, define a relevant behavior. Otherwise, display the
contact information, one field per line.
*/

/*EXIT
	Quit and contacts are lost forever!
*/

//Ignore any other input.
#include "Utils.hpp"

int	main() {
	size_t	option = 0;

	std::cout << IB << "PhoneBook open!" << RES << std::endl;
	while (option != EXIT) {
		display_options();
		option = get_option();
		break;
	}
	return 0;
}