/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:23:25 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/04/14 20:56:13 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data		baseStructure;

	uintptr_t	raw;
	Data*		deserialized;

	raw = Serializer::serialize(&baseStructure);
	deserialized = Serializer::deserialize(raw);

	if (&baseStructure == deserialized)
		std::cout << "Pointers are equal" << std::endl;
	return 0;
}
