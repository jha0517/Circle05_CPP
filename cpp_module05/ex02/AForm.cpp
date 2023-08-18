/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunah <hyunah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:24:14 by hyunah            #+#    #+#             */
/*   Updated: 2023/01/13 16:29:29 by hyunah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printColor.hpp"
#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(const char *message) : message(message) {}
const char *AForm::GradeTooHighException::what() const throw(){return (message);}

AForm::GradeTooLowException::GradeTooLowException(const char *message) : message(message) {}
const char *AForm::GradeTooLowException::what() const throw(){return (message);}

AForm::AForm(): name("DefaultAForm"), requiredGrade(150), requiredExec(149) {
    std::cout << "Default AForm Constructor Called" << std::endl;
    isSigned = 0;
}

AForm::AForm(std::string const pName, int const pRequiredGrade, int const pRequiredExec, std::string const pTarget) : name(pName), requiredGrade(pRequiredGrade), requiredExec(pRequiredExec), target(pTarget) {
    isSigned = 0;
    if (requiredGrade < 1 || requiredExec < 1)
        throw GradeTooHighException("Error : Exceeding Max value( highest : 1)");
    if (requiredGrade > 150 || requiredExec > 150)
        throw GradeTooLowException("Error : Exceeding Min value (lowest : 150)");
    std::cout <<"[" << this->name << "], required grade [" << requiredGrade <<"] constructor Called." << std::endl;
}

AForm::~AForm(){std::cout << "[" << this->name << "] Destructor Called" << std::endl;}

std::string AForm::getName() const {return (name);}

bool    AForm::getIsSigned() const {return (isSigned);}

void    AForm::setIsSigned(bool const b) {isSigned = b;}

int AForm::getRequiredGrade() const {return (requiredGrade);}

int AForm::getRequiredExec() const {return (requiredExec);}

std::string AForm::getTarget() const {return (target);}

void    AForm::setTarget(std::string const t) {target = t;}

std::string AForm::getSignedBy() const {return (signedBy);}

void    AForm::setSignedBy(std::string const name) {signedBy = name;}

int AForm::checkExecutable(Bureaucrat const & executor) const{
    if (!isSigned){
        throw GradeTooHighException("Error : Execution fail. Form not Signed");
    }
    if (executor.getGrade() > requiredExec){
        throw GradeTooHighException("Error : Grade Too Low to Execute");
    }
    return (1);
}

std::ostream & operator<<(std::ostream &o, const AForm &rhs){
    o << "---------------------PRINT Form-------------------" << std::endl;
    o << "[" << rhs.getName() << "] is ";
    if (!rhs.getIsSigned())
        o << "NOT ";
    o << "signed";
    if (rhs.getIsSigned())
        o << " by [" + rhs.getSignedBy() << "]";
    o << std::endl;
    o << ". (Min Required grade : " << rhs.getRequiredGrade() << "]"<< std::endl;
    o << ". (Min Required Exec : " << rhs.getRequiredExec() << "]"<< std::endl;
    o << ". (Target : " << rhs.getTarget() << "]"<< std::endl;
    o << "--------------------------------------------------" << std::endl << std::endl;
    return (o);
}

void        AForm::beSigned(Bureaucrat &b){
    if (b.getGrade() > this->requiredGrade){
        throw GradeTooLowException("Error : Bureaucrat Unqualified for signature.");
    }
    if (!isSigned)
    {
        isSigned = true;
        signedBy = b.getName();
        b.signForm(*this);
    }
    else
        print_red("[" + name + "] is already signed!");
}