/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:19:08 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 19:46:48 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H
# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
class Intern
{
    public:
        Intern();
        Intern(const Intern &rhs);
        ~Intern();
        Intern & operator=(const Intern &rhs);

        AForm	*makeShrubberyF(std::string const target);
        AForm	*makeRobotomyF(std::string const target);
        AForm	*makePresidentF(std::string const target);
        AForm	*makeForm(std::string form, std::string target);
};

#endif