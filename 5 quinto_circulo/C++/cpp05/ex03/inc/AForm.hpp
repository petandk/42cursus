/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:14:49 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/16 18:43:27 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm{
	public:
		AForm(void);
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		
		virtual ~AForm(void);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		int					requiredSignGrade(void) const;
		int					requiredExecuteGrade(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);

		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooHighException:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class AlreadySignedForm:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class FormNotSigned:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
		void				_checkGrade(int grade, const std::string &gradeType);

	protected:
		void	checkExecutionRequirements(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif