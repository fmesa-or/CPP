/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:50:12 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/10/28 18:26:17 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = -1;
	(void)argv;
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else if (argc > 1 && argv)
	{
		while (i < argc)
		{
			while (argv[i][++j])
				std::cout << (char)std::toupper(argv[i][j]);
			std::cout << " ";
			i++;
			j = -1;
		}
		std::cout << std::endl;
	}
	return (0);
}