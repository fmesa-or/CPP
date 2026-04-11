/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:27:26 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/03/19 17:01:10 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include "Utils.hpp"

class Base
{
	public:
		virtual	~Base();

		Base* generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};


#endif
