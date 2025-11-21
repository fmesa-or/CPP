/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:37:01 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/21 12:44:04 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedIsForLosers.hpp"

std::string	readFileContent(const std::string filename) {
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: fail to open " + filename);

	if (file.is_open()) {
		std::string	line;
		while (std::getline(file, line)) {

		}
		file.close();
	}
	return ();
}