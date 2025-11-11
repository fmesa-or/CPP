/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:24:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/11 14:04:28 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//SETTERS

void	Contact::settFirstName(const std::string& firstName) {
	_firstName = firstName;
}

void	Contact::setLastName(const std::string& lastName) {
	_lastName = lastName;
}

void	Contact::setNickName(const std::string& nickName) {
	_nickName = nickName;
}

void	Contact::setPhoneNumber(const std::string& phoneNumber) {
	_phoneNumber = phoneNumber;
}

void	Contact::setSecret(const std::string& secret) {
	_darkestSecret = secret;
}

