/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:24:31 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/10 15:58:32 by fmesa-or         ###   ########.fr       */
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
	return str.substr(start, end - start + 1);
}

void	error_msg(const std::string error_msg) {
	std::cout << RD << "Error\n" << error_msg << std::endl;
}

/**
 * 
 */
size_t	get_option(void) {
	std::string	line;
	size_t		option;

	while(true) {
		std::cout << YL << "Enter a valid option number: " << std::flush;
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
