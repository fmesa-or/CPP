/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:02:40 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/21 14:21:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB {
	private:
		std::string	_name;
		Weapon*		_weapon;
	public:
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
		void	setWeapon(Weapon& new_weapon);
		void	attack(void);
};

#endif
