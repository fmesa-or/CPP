/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:36:26 by fmesa-or          #+#    #+#             */
/*   Updated: 2025/12/23 13:15:10 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const char *new_name, unsigned int new_grade);
		Bureaucrat(const std::string &new_name, unsigned int new_grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		//GETTERS
		const std::string&	getName() const;
		unsigned int		getGrade() const;

		//SETTER
		void	setGrade(unsigned int new_grade);

		void	incrementGrade(); //terminar
		void	decrementGrade(); //terminar

		//EXCEPTIONS
		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};
};

//OPERATOR
std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
