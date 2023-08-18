/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:29:06 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/08 11:09:24 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "DefaultTarget") {
    std::cout << "Default PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const t) : AForm("PresidentialPardonForm", 25, 5, t) {
	std::cout << "Param PresidentialPardonForm Constructor Called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "[" << this->getName() << "] Destructor Called" << std::endl;
}

void	copyParam(PresidentialPardonForm const &from, PresidentialPardonForm &to)
{
	to.setIsSigned(from.getIsSigned());
	to.setSignedBy(from.getSignedBy());
	to.setTarget(from.getTarget());
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & form) : AForm("PresidentialPardonForm", 25, 5, form.getTarget()) {
	std::cout << "Copy PresidentialPardonForm Constructor Called" << std::endl;
	copyParam(form, *this);
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs) {
    std::cout << "Assignement Form Constructor Called" << std::endl;
    if (this != &rhs){
		copyParam(rhs, *this);
    }
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (this->checkExecutable(executor))
	{
		std::string str;
		str = "PresidentialPardonForm\n. signed by : " + this->getSignedBy();
		str += "\n";
		str += ". executed by : " + executor.getName();
		str += "\n";
		str += "------------------------------------------------------\n";
		str += this->getTarget();
		str += " has been pardoned by Zaphod Beeblebrox\n";
		str += "------------------------------------------------------";
		print_yellow(str);
	}
}
