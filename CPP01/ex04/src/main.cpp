/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:28:56 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 12:56:45 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedIsForLosers.hpp"

int	main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Error: Bad input.\tInput needed: filename, string 1 and string 2" << std::endl;
		return 1;
	}
	
	const std::string	filename = argv[1];
	const std::string	s1 = argv[2];
	const std::string	s2 = argv[3];

	try {
		std::string	file_content = readFileContent(filename);
		replaceFileContent(file_content, s1, s2);
		writeFileContent(filename + ".replace", file_content);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
