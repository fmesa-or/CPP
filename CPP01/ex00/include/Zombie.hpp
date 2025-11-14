/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:46:07 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/14 13:09:51 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include "utils.hpp"

/* CLASSES */
class	Zombie {
	private:
		std::string	_name;
	public:
		Zombie(std::string name);
		~Zombie();
		void		announce(void);
};

/* FUNCTIONS */
Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif