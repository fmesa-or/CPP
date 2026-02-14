/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 12:01:51 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/14 14:39:00 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "utils.hpp"

class Bureaucrat; // Forward Declaration because I only use pointers (*) or references (&) in this class

class Form {
	private:
		const std::string		_name;
		bool					_isSigned;
		const unsigned int		_gradeToSign;
		const unsigned int		_gradeToExecute;

	public:
		Form(void);
		Form(std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form(void);

		// GETTERS
		const std::string&	getName() const;
		bool			getIsSigned() const;
		unsigned int	getGradeToSign() const;
		unsigned int	getGradeToExecute() const;

		//EXCEPTIONS
		class GradeTooHighException : public std::exception {
			public:
				const char *what(void) const throw();
		};
		
		class GradeTooLowException : public std::exception {
			public:
				const char *what(void) const throw();
		};


		// MEMBER FUNCTIONS
		void	beSigned(const Bureaucrat& bureaucrat);
};

// OPERATOR
std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif
