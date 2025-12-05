/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 11:14:22 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/05 11:27:31 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include "utils.hpp"

class WrongAnimal {
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string newType);
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal(void);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
