/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:17 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/10 14:11:01 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

/* CLASSES*/
class PhoneBook {
	//array of contacts
	//max 8 contacts
	//if add 9th, replaces the oldest
	//dinamic allocation is forbidden
	private:
		Contact	contacts[8];
		size_t	contactCount;
	public:
		PhoneBook();
};

#endif
