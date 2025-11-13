/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:17 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 11:44:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

/* CLASSES*/
class PhoneBook {
	private:
		Contact	_contacts[8];
		size_t	_contactCount;
		void	storeContact(const Contact& contact);
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
		void	printContactsTable(size_t maxContacts) const;
		void	showContactInfo(std::string line) const;
};
#endif
