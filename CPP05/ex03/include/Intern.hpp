/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 11:40:38 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/20 12:09:53 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "utils.hpp"

class AForm;

class Intern {
	private:
		//creadores de formulario
	public:
		Intern(void);
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern(void);

		AForm*	makeForm(std::string formName, std::string targetForm);
};

#endif
