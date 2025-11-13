/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:03:04 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 11:25:25 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/********************************************************
 * This is the CONSTRUCTOR. Sets the contactCount value.*
 *******************************************************/
PhoneBook::PhoneBook(void) : _contactCount(0) {
	std::cout << "\nCONSTRUCTOR IS CALLED.\n" << std::endl;
}

/**************************
 * This is the DESTRUCTOR.*
 *************************/
PhoneBook::~PhoneBook(void) {
	std::cout << "\nDESTRUCTOR IS CALLED.\n" << std::endl;
}

/*********************************************************************
 * Saves //contact// inside the next position in //_contacts// array.*
 ********************************************************************/
void	PhoneBook::storeContact(const Contact& contact) {
	_contacts[_contactCount % 8] = contact;
	_contactCount++;
	std::cout << GR << "\n\tContact added succesfully!\n" << RES << std::endl;
}


/*****************************************
 * Collects all the data for the contact.*
 ****************************************/
void	PhoneBook::addContact() {
	Contact newContact;
	newContact.settFirstName(get_user_input("\nEnter first name: "));
	newContact.setLastName(get_user_input("Enter last name: "));
	newContact.setNickName(get_user_input("Enter nick name: "));
	newContact.setPhoneNumber(get_user_input("Enter phone number: "));
	newContact.setSecret(get_user_input("Enter the darkest secret of this contact: "));
	storeContact(newContact);
}

/****************************
 * Need //maxContacts// var.*
 ***************************/
void	PhoneBook::printContactsTable(size_t maxContacts) const {
	size_t	i;

	std::cout << "---------------------------------------------\n"
		<< "|     Index|First Name| Last Name|  Nickname|\n"
		<< "---------------------------------------------" << std::endl;
	i = 0;
	while (i < maxContacts) {
		std::cout << "|    " << i + 1 << "     |"
			<< std::setw(10) << format_field(_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << format_field(_contacts[i].getLastName()) << "|"
			<< std::setw(10) << format_field(_contacts[i].getNickName()) << "|"
			<< std::endl;
		i++;
	}
	std::cout << "---------------------------------------------\n" << std:: endl;
}

/**********************************************************************
 * Needs numeric input as //std::string// var to convert to //size_t//*
 *********************************************************************/
void	PhoneBook::showContactInfo(std::string line) const {
	std::stringstream	iss(line);
	size_t				index;

	if (!(iss >> index))
		error_msg("Bad input.");
	std::cout << CI << "\nFirst Name: " << RES << _contacts[index -1].getFirstName() << std::endl;
	std::cout << CI << "Last Name: " << RES << _contacts[index -1].getLastName() << std::endl;
	std::cout << CI << "Nickname: " << RES << _contacts[index -1].getNickName() << std::endl;
	std::cout << CI << "Phone Number: " << RES << _contacts[index -1].getPhoneNumber() << std::endl;
	std::cout << CI << "Darkest secret: " << RES << _contacts[index -1].getDarkestSecret() << '\n' << std::endl;

	
}

/************************************
 * Sets max contacts number (1 ~ 8).*
 * Prints contact list.             *
 * Shows data from indexed contact. *
 ***********************************/
void	PhoneBook::searchContact() {
	size_t	maxContacts;
	
	if (_contactCount == 0) {
		error_msg("PhoneBook empty!! Try add someone!\n");
		return ;
	}
	else if (_contactCount < 8)
		maxContacts = _contactCount;
	else
		maxContacts = 8;
	printContactsTable(maxContacts);
	showContactInfo(get_index_input(maxContacts));
}
