/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:25:07 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/14 20:41:35 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**************
 * Constructor*
 *************/
ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter has been created." << std::endl;
}

/*******************
 * Copy constructor*
 ******************/
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

/**********************
 * Assignment operator*
 *********************/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

/*************
 * Destructor*
 ************/
ScalarConverter::~ScalarConverter(void) {}

/* METHODS */

/************************************************************************
 * Detects if it's a char.                                              *
 *	It's divided in two modules:                                        *
 *		First:                                                          *
 *			Logic for internal call, ex.: ScalarConverter::convert('a');*
 *		Second:                                                         *
 *			Logic for external call, ex.: ./ScalarConvert "a" ;         *
 ***********************************************************************/
bool	isChar(const std::string& str) {
	char	c;

	if (str.length() == 3 && 
		(!std::isdigit(str[1]) &&
			((str[0] == '\'' && str[2] == '\'') || (str[0] == '\"' && str[2] == '\"')))) {
		c = str[1];

		std::cout << YL << "Char:\t" << CI IT << c << RES << std::endl;
		std::cout << YL << "Int:\t" << CI IT << static_cast<int>(c) << RES << std::endl;
		std::cout << YL << "Float:\t" << CI IT << static_cast<float>(c) << "f" << RES << std::endl;
		std::cout << YL << "Double:\t" << CI IT << static_cast<double>(c) << RES << std::endl;

		return true;
	}
	else if (str.length() == 1 && !std::isdigit(str[0])) {
		c = str[0];
		if (c >= 32 && c <= 126) {

			std::cout << YL << "Char:\t" << CI IT << c << RES << std::endl;
			std::cout << YL << "Int:\t" << CI IT << static_cast<int>(c) << RES << std::endl;
			std::cout << YL << "Float:\t" << CI IT << static_cast<float>(c) << "f" << RES << std::endl;
			std::cout << YL << "Double:\t" << CI IT << static_cast<double>(c) << RES << std::endl;

			return true;
		}
		else
			std::cout << RD << "Error: Input not printable." << RES << std::endl;
	}

	return false;
}

/*************************************
 * Checks if the @param str is empty *
 *************************************/
bool	isEmpty(const std::string& str) {
	if (str.length() == 0) {
		std::cerr << RD << "Error: Bad input: Input must not be empty." << RES << std::endl;
		return true;
	}
	return false;
}

/*****************************************************
 * Checks for -inf, +inf, nan, -inff, +inff and nanf.*
 ****************************************************/
bool	isSpecial(const std::string& str) {
	std::string	doubleExceptions[] = {"nan", "-inf", "+inf"};
	size_t	count = sizeof(doubleExceptions) / sizeof(doubleExceptions[0]);

	for(size_t i = 0; i < count; ++i) {
		if (str == doubleExceptions[i]) {
			std::cout << YL << "Char:\t" << RD IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Int:\t" << RD IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Float:\t" << CI IT << str << "f" << RES << std::endl;
			std::cout << YL << "Double:\t" << CI IT << str << RES << std::endl;

			return true;
		}
	}
	std::string	floatExceptions[] = {"nanf", "-inff", "+inff"};
	count = sizeof(floatExceptions) / sizeof(floatExceptions[0]);

	for(size_t i = 0; i < count; ++i) {
		if (str == floatExceptions[i]) {
			std::cout << YL << "Char:\t" << RD IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Int:\t" << RD IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Float:\t" << CI IT << str << RES << std::endl;
			std::cout << YL << "Double:\t" << CI IT << doubleExceptions[i] << RES << std::endl;

			return true;
		}
	}

	return false;
}

/*********************************************************************************
 * Prints all difrent options. Also if something could not be printed, shows it. *
 ********************************************************************************/
static void	numPrinter(const double	value) {

	if (value < 32 || value >= 127)
		std::cout << YL << "Char:\t" << CI IT << "Non displayable" << RES << std::endl;
	else
		std::cout << YL << "Char:\t" << CI IT << static_cast<char>(value) << RES << std::endl;

	std::cout << YL << "Int:\t" << CI IT << static_cast<int>(value) << RES << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << YL << "Float:\t" << CI IT << static_cast<float>(value) << "f" << RES << std::endl;
	std::cout << YL << "Double:\t" << CI IT << static_cast<double>(value) << RES << std::endl;
}

/**********************************************
 * Prints all options with value: Impossible. *
 *********************************************/
static void	imposiblePrint(void) {
	std::cout << YL << "Char:\t" << RD IT << "Impossible" << RES << std::endl;
	std::cout << YL << "Int:\t" << RD IT << "Impossible" << RES << std::endl;
	std::cout << YL << "Float:\t" << RD IT << "Impossible" << RES << std::endl;
	std::cout << YL << "Double:\t" << RD IT << "Impossible" << RES << std::endl;
}

/*****************************************************************************
 * Detects if it's an integer, a doble or a float and then prints it's value.*
 ****************************************************************************/
bool	isNum(const std::string& str) {
	std::string			strNew = str;
	std::size_t			fPos = strNew.find('f');

	if (fPos != std::string::npos){
		if (fPos == strNew.size() - 1)
			strNew.erase(strNew.size() - 1);
		else {
			imposiblePrint();
			return false;
		}
	}

	std::size_t	dot = strNew.find('.');
	if (dot != std::string::npos && strNew.find('.', dot + 1) != std::string::npos) {
		imposiblePrint();
		return false;
	}

	std::istringstream	arg(strNew);
	double				value;
	if (!(arg >> value) || !arg.eof()) {
		imposiblePrint();
		return false;
	}

	numPrinter(value);

	return true;
}



/*********************************
 * Converts a string to a value: *
 * 	char, int, float or double   *
 ********************************/
void	ScalarConverter::convert(const std::string& str) {

	if (isEmpty(str))
		return;
	if (isSpecial(str))
		return;
	if (isChar(str))
		return;
	if (isNum(str))
		return;
}
