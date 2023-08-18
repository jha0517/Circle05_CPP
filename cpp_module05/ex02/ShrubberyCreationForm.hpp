/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:29:16 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/08 13:31:44 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H
# include <iostream>
# include <string>
# include <fstream>
# include <stdexcept>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(const ShrubberyCreationForm & form);
		virtual	~ShrubberyCreationForm();
		
		void	execute(Bureaucrat const & executor) const;
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &rhs);
};

#endif