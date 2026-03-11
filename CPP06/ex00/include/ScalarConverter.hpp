/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:05:33 by oceanscore        #+#    #+#             */
/*   Updated: 2026/03/11 15:15:29 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "utils.hpp"
#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter(void);

		// METHODS
//		bool	isNotPrintable(std::string& str);
	public:
		static void convert(const std::string& str);

};


	bool	isChar(const std::string& str);
	bool	isEmpty(const std::string& str);
	bool	isSpecial(const std::string& str);
	bool	isNum(const std::string& str);
	bool	isInt(const std::string& str);

#endif
