/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:32:01 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/14 20:53:37 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Utils.hpp"

struct	Data {
	int	num;
};

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif
