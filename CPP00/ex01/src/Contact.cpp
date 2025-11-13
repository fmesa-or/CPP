/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:24:44 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 13:55:35 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/********************************************************
 * This is the CONSTRUCTOR. Sets the contactCount value.*
 *******************************************************/
Contact::Contact(void) {
	std::cout << "\nContact CONSTRUCTOR IS CALLED.\n" << std::endl;
}

/**************************
 * This is the DESTRUCTOR.*
 *************************/
Contact::~Contact(void) {
	std::cout << "\nContact DESTRUCTOR IS CALLED.\n" << std::endl;
}

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

//GETTERS

std::string	Contact::getFirstName(void) const {
	return (_firstName);
}

std::string	Contact::getLastName(void) const {
	return (_lastName);
}

std::string	Contact::getNickName(void) const {
	return (_nickName);
}

std::string	Contact::getPhoneNumber(void) const {
	return (_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const {
	return (_darkestSecret);
}