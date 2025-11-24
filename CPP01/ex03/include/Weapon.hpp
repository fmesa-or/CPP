/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:32:27 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 12:19:32 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include "utils.hpp"

/* CLASS */
class	Weapon {
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(std::string newType);
		~Weapon(void);
		const std::string&	getType(void) const;
		void				setType(std::string newType);
};

#endif
