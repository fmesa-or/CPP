/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:24:31 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/11 14:24:45 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

/************************************************
 * Prints the options abailables in the program.*
 ***********************************************/
void	display_options(void) {
	std::cout << YL << "Options:\n" << RES;
	std::cout << CI << "-> 1.ADD\n-> 2.SEARCH\n-> 3.EXIT\n" << RES;
}

/**********************************************
 * If Ctrl + D is detected, exits the program.*
 *********************************************/
void	handle_eof(void) {
	if (std::cin.eof()) {
		std::cout << RD << "\nEOF detected.\tExiting..." << RES << std::endl;
		exit(0);
	}
}

/**************************************************************
 * Checks for blank spaces of any kind.                       *
 * Looks where the text starts and where it ends and trims it.*
 *************************************************************/
std::string	strtrim(std::string& str) {
	const std::string	whitespaces = " \t\n\r\f\v";

	std::string::size_type start = str.find_first_not_of(whitespaces);
	if (start == std::string::npos)
		return "";
	std::string::size_type end = str.find_last_not_of(whitespaces);
	return (str.substr(start, end - start + 1));
}

/****************************************************************
 * Displays Error followed by a line jump and the text inserted.*
 ***************************************************************/
void	error_msg(const std::string error_msg) {
	std::cout << RD << "Error\n" << error_msg << std::endl;
}

/*******************************************************
 * Loop. Displays error until a good input is inserted.*
 ******************************************************/
size_t	get_option(void) {
	std::string	line;
	size_t		option;

	while(true) {
		std::cout << YL << "Enter a valid option number: " << RES << std::flush;
		std::getline(std::cin, line);
		handle_eof();
		line = strtrim(line);
		if (line.empty()) {
			error_msg("Invalid input. Choose 1, 2 or 3.");
			display_options();
			continue;
		}
		if (line.length() != 1 || !std::isdigit(line[0])) {
			error_msg("Invalid input. Choose 1, 2 or 3.");
			display_options();
			continue;
		}
		option = line[0] - '0';
		if (option < 1 || option > 3) {
			error_msg("Invalid input. Choose 1, 2 or 3.");
			continue;
		}
		break;
	}
	return (option);
}

std::string	get_user_input(std::string msg) {
	std::string	line;

	while (true) {
		std::cout << PI << msg << RES << std::flush;
		std::getline(std::cin, line);
		handle_eof();
		if (line.empty()) {
			std::cout << RD << "Empty input! Try again!\n" << RES << std::flush;
			continue;
		}
		break;
	}
	return (line);
}
