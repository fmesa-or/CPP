/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:03:04 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/11 14:08:10 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

//Preguntar a Antonimo por que hay que poner esto!
PhoneBook::PhoneBook(void) {
	contactCount = 0;
}


void	PhoneBook::storeContact(const Contact& contact) {
	contacts[contactCount % 8] = contact;
	contactCount++;
	std::cout << GR << "Contact added succesfully!" << RES << std::endl;
}


/*****************************************
 * Collects all the data for the contact.*
 ****************************************/
void	PhoneBook::addContact() {
	Contact newContact;
	newContact.settFirstName(get_user_input("Enter first name: "));
	newContact.setLastName(get_user_input("Enter last name: "));
	newContact.setNickName(get_user_input("Enter nick name: "));
	newContact.setPhoneNumber(get_user_input("Enter phone number: "));
	newContact.setSecret(get_user_input("Enter the darkest secret of this contact: "));
	storeContact(newContact);
}


