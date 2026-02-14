/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesa-or <fmesa-or@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 15:10:03 by fmesa-or          #+#    #+#             */
/*   Updated: 2026/02/14 15:17:37 by fmesa-or         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "utils.hpp"

class Bureaucrat; // Forward Declaration because I only use pointers (*) or references (&) in this class

class AForm {
	private:
		const std::string		_name;
		bool					_isSigned;
		const unsigned int		_gradeToSign;
		const unsigned int		_gradeToExecute;

	public:
		AForm(void);
		AForm(std::string name, const unsigned int gradeToSign, const unsigned int gradeToExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm(void);

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
		virtual void	execute(Bureaucrat const & executor) const; // This makes the class abstract
};

// OPERATOR
std::ostream	&operator<<(std::ostream &os, const AForm &form);

#endif