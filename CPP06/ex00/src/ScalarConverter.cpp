/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:25:07 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/11 19:10:34 by fmesa-or         ###   ########.fr       */
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

/************************************************************************
 * Detects if it's a char.                                              *
 * 	It's divided in two modules:                                        *
 * 		First:                                                          *
 * 			Logic for internal call, ex.: ScalarConverter::convert('a');*
 * 		Second:                                                         *
 * 			Logic for external call, ex.: ./ScalarConvert "a" ;         *
 ***********************************************************************/
bool	ScalarConverter::isChar(const std::string& str) {
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

bool	ScalarConverter::isEmpty(const std::string& str) {
	if (str.length() == 0) {
		std::cout << RD << "Error: Bad input: Input must not be empty." << RES << std::endl;
		return true;
	}
	return false;
}

/*****************************************************
 * Checks for -inf, +inf, nan, -inff, +inff and nanf.*
 ****************************************************/
bool	ScalarConverter::isSpecial(const std::string& str) {
	std::string	doubleExceptions[] = {"nan", "-inf", "+inf"};
	size_t	count = sizeof(doubleExceptions) / sizeof(doubleExceptions[0]);

	for(size_t i = 0; i < count; ++i) {
		if (str == doubleExceptions[i]) {
			std::cout << YL << "Char:\t" << CI IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Int:\t" << CI IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Float:\t" << CI IT << str << "f" << RES << std::endl;
			std::cout << YL << "Double:\t" << CI IT << str << RES << std::endl;
			
			return true;
		}
	}
	std::string	floatExceptions[] = {"nanf", "-inff", "+inff"};
	count = sizeof(floatExceptions) / sizeof(floatExceptions[0]);

	for(size_t i = 0; i < count; ++i) {
		if (str == floatExceptions[i]) {
			std::cout << YL << "Char:\t" << CI IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Int:\t" << CI IT << "Impossible" << RES << std::endl;
			std::cout << YL << "Float:\t" << CI IT << str << RES << std::endl;
			std::cout << YL << "Double:\t" << CI IT << doubleExceptions[i] << RES << std::endl;
			
			return true;
		}
	}

	return false;
}


/**
 * Works with float & double
 */
/*
bool	ScalarConverter::isNum(const std::string& str) {


	return false;
}
*/

bool	ScalarConverter::isInt(const std::string& str) {

	return false;
}



/*********************************
 * Converts a string to a value: *
 * 	char, int, float and double   *
 ********************************/
void	ScalarConverter::convert(const std::string& str) {
	// Salvo caracteres, los valores numericos deben ser en notación decimal
	// Solo caracteres validos. Mostrar mensaje en caso de ser non-displayable
	// Manejar [-inff, +inff y nanf] y [-inf, +inf y nan]

	if (isEmpty(str))
		return;
	if (isChar(str))
		return;
	if (isSpecial(str))
		return;
/*	if (str.find('.') && isNum(str))
		return;
*/
	if (isInt(str))
		return;


	// Crear un metodo para revisar si es imprimible en int e imprimir su valor
	// '' float
	// '' double

}
