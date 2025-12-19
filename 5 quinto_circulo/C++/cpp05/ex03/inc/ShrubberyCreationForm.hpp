/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:35:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/12/16 17:47:35 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFROM_HPP
# define SHRUBBERYCREATIONFROM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		const std::string	&getTarget(void) const;
		void				execute(Bureaucrat const &executor) const;

		class FileCreationException:public std::exception{
			public:
				virtual const char *what() const throw();
		};
		
	private:
		const std::string _target;
};

#endif