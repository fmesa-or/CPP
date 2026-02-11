/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:09:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/11 15:16:30 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << RD << "Error: usage: ./ScalarConverter <value>" << RES << std::endl;
		return 1;
	}
	(argv)++;
	ScalarConverter::convert(*argv);
	return 0;
}
