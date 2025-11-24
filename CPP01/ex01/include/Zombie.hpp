/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:06:58 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/11/24 12:17:36 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "utils.hpp"

/* CLASSES */
class	Zombie {
	private:
		std::string	_name;
	public:
		Zombie();
		~Zombie();
		void	setName(std::string name);
		void	annouce(int i);
};

/* FUNCTIONS */
Zombie*	zombieHorde(int N, std::string name);

#endif
