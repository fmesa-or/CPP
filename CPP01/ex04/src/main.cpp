/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:28:56 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/20 20:41:26 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/**
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
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
#include <iostream>

int	main(int argc, std::string argv) {
	if (argc != 4)
		// error_msg("Input needed: filename, string 1 and string 2")
	else
		// CODE
			/*	-Find filename 
				-Check if filename could be open and readed
				-Create filename.replace
				-*/
	return 0;
}