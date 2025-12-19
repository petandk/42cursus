/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 19:51:01 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/16 18:50:02 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class AForm;

class Bureaucrat{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name);
		Bureaucrat(int grade);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		
		~Bureaucrat(void);

		const  std::string	&getName(void) const;
		int					getGrade(void) const;
		void				signForm(AForm &form);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char *what() const throw();
		};

		void	upgrade(void);
		void	downgrade(void);

		void	executeForm(AForm const &form) const;
	
	private:
		const std::string	_name;
		int					_grade;
		void				_checkGrade(int grade);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
#endif