/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:59:15 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 11:16:50 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
