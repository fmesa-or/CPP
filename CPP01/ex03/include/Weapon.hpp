/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:32:27 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/18 18:05:11 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

/* COLORS */
# define GR		"\033[1;92m"
# define RD		"\033[1;31m"
# define CI		"\033[0;96m"
# define IB		"\033[0;94m"
# define YL		"\033[0;93m"
# define PI		"\033[1;35m"
# define RES	"\033[0m"

/* CLASS */
class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(std::string newType);
		~Weapon(void);
		const std::string&	getType(void) const;
		void				setType(std::string newType);
};

#endif
