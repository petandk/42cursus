/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:14:49 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/09 17:36:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Form{
	public:
		Form(void);
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		
		~Form(void);

		const std::string &getName(void) const;
		bool		isSigned(void) const;
		int			requiredSignGrade(void) const;
		int			requiredExecuteGrade(void) const;
		
		class GradeTooHighException:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_executeGrade;
		void				_checkGrade(int grade, const std::string &gradeType);
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif