/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:18:46 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/13 11:45:43 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

/* INCLUDES */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

/* COLORS */
# define GR		"\033[1;92m"
# define RD		"\033[1;31m"
# define CI		"\033[0;96m"
# define IB		"\033[0;94m"
# define YL		"\033[0;93m"
# define PI		"\033[1;35m"
# define RES	"\033[0m"

/* OPTIONS */
# define	ADD		1
# define	SEARCH	2
# define	EXIT	3

/* FUNCTIONS */

/** UTILS **/
void		display_options(void);
void		handle_eof(void);
std::string	strtrim(std::string& str);
void		error_msg(const std::string error_msg);
size_t		get_option(void);
std::string	get_user_input(std::string msg);
std::string	format_field(const std::string& str);
std::string	get_index_input(size_t maxContacts);

#endif