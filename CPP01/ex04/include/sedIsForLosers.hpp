/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sedIsForLosers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 11:25:25 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/21 12:40:03 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEDISFORLOSERS_HPP
#define SEDISFORLOSERS_HPP

#include <iostream>
#include <fstream>

/*

It must open the file <filename> and copy its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.

Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!

Of course, handle unexpected inputs and errors. You must create and turn in your
own tests to ensure that your program works as expected.
13

FORBIDDEN STD::STRING::REPLACE
*/

/* FUNCTIONS */
std::string	readFileContent(const std::string filename);
void		replaceFileContent(std::string file_content, const std::string s1,
				const std::string s2);
void		writeFileContent(std::string filename, std::string file_content);

#endif