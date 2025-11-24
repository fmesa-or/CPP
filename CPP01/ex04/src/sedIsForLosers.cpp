/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedIsForLosers.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 12:37:01 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 12:39:48 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sedIsForLosers.hpp"

/*************************************************************
 * Recives the name of the file @param filename.             *
 * Returns a string with its content as @param file_copntent.*
 * Converts filename as a constant with .c_str method.       *
 * Then uses is_open to check if file can be open, and uses  *
 * getline to extract content.                              *
 ************************************************************/
std::string	readFileContent(const std::string& filename) {
	std::ifstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: fail to open " + filename);

	std::string	file_content;
	std::string	line;

	while (std::getline(file, line)) {
		file_content += line;
		if (!file.eof())
			file_content += '\n';
	}
	return file_content;
}

/**************************************************************************
 * Recieves a reference of @param file_content and two constant strings,  *
 * first @param s1 for replace with second @param s2.                     *
 *                                                                        *
 * Finds where @param s1 starts inside of the file and                    *
 * substitudes it with @param s2.                                         *
 *************************************************************************/
void	replaceFileContent(std::string& file_content, const std::string& s1, const std::string& s2) {
	if (s1.empty() || s2.empty())
		return ;
	
	size_t	init_pos = 0;
	size_t	world_pos = file_content.find(s1, init_pos);
	std::string	new_content;

	while(world_pos != std::string::npos) {
		new_content.append(file_content.substr(init_pos, world_pos - init_pos));
		new_content.append(s2);
		init_pos = world_pos + s1.length();
		world_pos = file_content.find(s1, init_pos);
	}
	new_content.append(file_content.substr(init_pos));
	file_content = new_content;
}

/*****************************************************************
 * Recieves a reference of the new filename with @param filename *
 * and the new content with @param file_contect                  *
 *                                                               *
 * Creates the output file (truncates if already exists).        *
 * Checks if it could be opened.                                 *
 * Writes the content into the file.                             *
 ****************************************************************/
void	writeFileContent(const std::string& filename, const std::string& file_content) {
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Error: failed to create or write in file " + filename);

	file << file_content;
}
