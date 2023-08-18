/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:29:09 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/08 13:40:49 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "DefaultTarget") {
    std::cout << "Default RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const t) : AForm("RobotomyRequestForm", 72, 45, t) {
	std::cout << "Param RobotomyRequestForm Constructor Called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "[" << this->getName() << "] Destructor Called" << std::endl;
}

void	copyParam(RobotomyRequestForm const &from, RobotomyRequestForm &to)
{
	to.setIsSigned(from.getIsSigned());
	to.setSignedBy(from.getSignedBy());
	to.setTarget(from.getTarget());
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & form) : AForm("RobotomyRequestForm", 72, 45, form.getTarget()) {
	std::cout << "Copy RobotomyRequestForm Constructor Called" << std::endl;
	copyParam(form, *this);
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs) {
    std::cout << "Assignement Form Constructor Called" << std::endl;
    if (this != &rhs){
		copyParam(rhs, *this);
    }
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (this->checkExecutable(executor))
	{
		std::string result;
		int			number;

		std::srand(std::time(NULL));
		number = std::rand();
		result = "RobotomyRequestForm\n. signed by : [" + this->getSignedBy() + "]\n";
		result += ". executed by : [" + executor.getName() + "]\n";
		result += "------------------------------------------------------\n";
		result += "Drilling noises....DDDDDDDRRRRRR.....\n";
		if (number % 2)
		{
			result += "Success!";
		}
		else
		{
			result += "Failed!";
		}
		result += "\n------------------------------------------------------\n";
		print_yellow(result);
	}
}
