/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:18:46 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/10 15:35:40 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

/* INCLUDES */
#include "iostream"
#include "cstdlib"

/* COLORS */
# define GR		"\033[0;92m"
# define RD		"\033[1;91m"
# define CI		"\033[0;96m"
# define IB		"\033[0;94m"
# define YL		"\033[0;93m"
# define RES	"\033[0m"

/* OPTIONS */
# define	ADD		1
# define	SEARCH	2
# define	EXIT	3


/* FUNCTIONS */

/** UTILS **/
void		display_options(void);
size_t		get_option(void);
void		handle_eof(void);
std::string	strtrim(std::string& str);


#endif