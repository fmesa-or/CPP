/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:27:26 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/03/19 16:33:11 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include "Utils.hpp"

class Base
{
	public:
		virtual	~Base();

		Base* generate(void); /* Randomly instantiates A, B or C class, and returns the isntance as a Base pointer.*/
		void	identify(Base* p); /*Prints the actual type of the object pointed to by p (A, B or C) */
		void	identify(Base& p); /*Same as other. Doesn't use a pointer inside this function*/
};


#endif
