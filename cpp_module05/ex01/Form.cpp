/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:24:14 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/10 19:32:50 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "printColor.hpp"

Form::GradeTooHighException::GradeTooHighException(const char *message) : message(message) {}
const char *Form::GradeTooHighException::what() const throw(){return (message);}

Form::GradeTooLowException::GradeTooLowException(const char *message) : message(message) {}
const char *Form::GradeTooLowException::what() const throw(){return (message);}

Form::CanNotChangeConst::CanNotChangeConst(const char *message) : message(message) {}
const char *Form::CanNotChangeConst::what() const throw(){ return message; }

Form::Form(): name("DefaultForm"), requiredGrade(150), requiredExec(149)
{
    isSigned = 0;
    std::cout << "Default Form Constructor Called" << std::endl;
}

Form::Form(std::string const name, int const requiredGrade, int const requiredExec) : name(name), requiredGrade(requiredGrade), requiredExec(requiredExec) {
    isSigned = 0;
    if (requiredGrade < 1 || requiredExec < 1)
        throw GradeTooHighException("Error : Creation Form Failed. Exceeding Max value( highest : 1)");
    if (requiredGrade > 150 || requiredExec > 150)
        throw GradeTooLowException("Error : Creation Form Failed. Exceeding Min value (lowest : 150)");
    if (requiredGrade <= requiredExec)
        throw GradeTooLowException("Error : Creation Form Failed. requiredExec should be higher than requiredGrade to sign");
    std::cout <<"[" << this->name << "] Form, required grade [" << requiredGrade <<"], required Exec ["<< requiredExec<<"] constructor Called." << std::endl;
}

Form::~Form()
{
    std::cout << "[" << this->name << "] Form Destructor Called" << std::endl;
}

Form::Form(const Form &rhs) : name(rhs.name), requiredGrade(rhs.requiredGrade), requiredExec(rhs.requiredExec)
{
    std::cout << "Copy Form Constructor Called" << std::endl;
    signedBy = rhs.signedBy;
    isSigned = rhs.isSigned;
}

Form & Form::operator=(const Form &rhs){    
    std::cout << "Assignement Form Constructor Called" << std::endl;
    if (this != &rhs){
        isSigned = rhs.getIsSigned();
        signedBy = rhs.signedBy;
        throw Bureaucrat::CanNotChangeConst("Error : Can not change CONST name/ CONST requiredGrade / CONST requiredExec. Other Attributes have been copied.");
    }
    return (*this);
}

std::string Form::getName() const {return (name);}

bool    Form::getIsSigned() const {return (isSigned);}

void    Form::setIsSigned(bool const b) {isSigned = b;}

int Form::getRequiredGrade() const {return (requiredGrade);}

int Form::getRequiredExec() const {return (requiredExec);}

std::string Form::getSignedBy() const {return (signedBy);}

void    Form::setSignedBy(std::string const name) {signedBy = name;}

std::ostream & operator<<(std::ostream &o, const Form &rhs){
    o << "---------------------PRINT FORM-------------------" << std::endl;
    o << "[" << rhs.getName() << "] is ";
    if (!rhs.getIsSigned())
        o << "NOT ";
    o << "signed";
    if (rhs.getIsSigned())
        o << " by [" + rhs.getSignedBy() << "]" << std::endl;
    o << ". (Min Required grade : " << rhs.getRequiredGrade() << "]"<< std::endl;
    o << ". (Min Required Exec : " << rhs.getRequiredExec() << "]"<< std::endl;
    o << "--------------------------------------------------" << std::endl;
    return (o);
}

void        Form::beSigned(Bureaucrat &b){
    if (b.getGrade() > this->requiredGrade){
        throw GradeTooLowException("Error : Bureaucrat couldn't sign because grade too low.");
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