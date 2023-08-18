/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:46:32 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/08 10:33:17 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Intern.hpp"
#include "printColor.hpp"

AForm	*Intern::makeShrubberyF(std::string const target){return (new ShrubberyCreationForm(target));}
AForm	*Intern::makeRobotomyF(std::string const target){return (new RobotomyRequestForm(target));}
AForm	*Intern::makePresidentF(std::string const target){return (new PresidentialPardonForm(target));}

Intern::Intern()
{
    std::cout << "Default Intern Constructor Called" << std::endl;
}

Intern::Intern(const Intern &rhs)
{
    std::cout << "Copy Intern Constructor Called" << std::endl;
    *this = rhs;
}

Intern::~Intern()
{
    std::cout <<"Intern Destructor Called" << std::endl;
}

Intern & Intern::operator=(const Intern &){    
    std::cout << "Assignement Intern Constructor Called" << std::endl;
    return (*this);
}

AForm	*Intern::makeForm(std::string formName, std::string const target){
    AForm *a;
	AForm *(Intern::*fonctionPtr[3])(const std::string) = {&Intern::makeShrubberyF, &Intern::makeRobotomyF, &Intern::makePresidentF};
	std::string request[3] = { "shrubbery request", "robotomy request", "presidential request"};
	for (int i = 0; i < 4; i++)
	{
		if (request[i] == formName)
		{
            std::string msg;
            msg = "Intern creates " + request[i] +" for [" + target + "].";
			a = (this->*fonctionPtr[i])(target);
            print_blue(msg);
			return (a);
		}
	}
    print_red("No available form.\n.Choose between\n-[shrubbery request]\n-[robotomy request]\n-[presidential request]");
    return (NULL);
}
