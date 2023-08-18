/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:29:14 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/08 13:41:45 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "DefaultTarget") {
    std::cout << "Default ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const t) : AForm("ShrubberyCreationForm", 145, 137, t) {
	std::cout << "Param ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "[" << this->getName() << "] Destructor Called" << std::endl;
}

void	copyParam(ShrubberyCreationForm const &from, ShrubberyCreationForm &to)
{
	to.setIsSigned(from.getIsSigned());
	to.setSignedBy(from.getSignedBy());
	to.setTarget(from.getTarget());
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & form) : AForm("ShrubberyCreationForm", 145, 137, form.getTarget()) {
	std::cout << "Copy ShrubberyCreationForm Constructor Called" << std::endl;
	copyParam(form, *this);
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs) {
    std::cout << "Assignement Form Constructor Called" << std::endl;
    if (this != &rhs){
		copyParam(rhs, *this);
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
	if (this->checkExecutable(executor))
	{
		std::string		str;
		std::string		fileName;
		fileName = this->getTarget() + "_shrubbery";
		std::ofstream	ofs(fileName.c_str());
		str = "Form [" + this->getName() + "] Execution File.\n. signed by : [ " + this->getSignedBy() + " ]\n. executed by [ " + executor.getName() + " ]";
		str += "\n\n       ###\
\n      #o###\
\n    #####o###\
\n   #o#\\#|#/###\
\n    ###\\|/#o#\
\n     # }|{  #\
\n.......}|{.......\n";
		ofs << str;
		if (!ofs)
		{
			std::cout << "File not created!" << std::endl;
		}
		ofs.close();
	}
}
