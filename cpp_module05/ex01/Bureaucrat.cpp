/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:46:32 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/10 19:35:46 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "printColor.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *message) : message(message) {}
const char *Bureaucrat::GradeTooHighException::what() const throw(){ return message; }

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *message) : message(message) {}
const char *Bureaucrat::GradeTooLowException::what() const throw(){ return message; }

Bureaucrat::CanNotChangeConst::CanNotChangeConst(const char *message) : message(message) {}
const char *Bureaucrat::CanNotChangeConst::what() const throw(){ return message; }

Bureaucrat::Bureaucrat() : name("DefaultGuy"), grade(150)
{
    std::cout << "Default Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const n, int const g) : name(n), grade(g)
{
    if (g < 1)
        throw GradeTooHighException("ERROR : Grade too high.");
    if (g > 150)
        throw GradeTooLowException("ERROR : Grade too low.");
    std::cout <<"[" << this->name << "] grade [" << this->grade <<"] Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout <<"[" << this->name << "] Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.getName()), grade(rhs.getGrade())
{
    std::cout << "Copy Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs){    
    std::cout << "Assignement Bureaucrat Constructor Called" << std::endl;
    if (this != &rhs){
        grade = rhs.getGrade();
        throw Bureaucrat::CanNotChangeConst("Error : Can not change CONST name. Only Grade has been copied.");
    }
    return (*this);
}

std::string Bureaucrat::getName() const{
    return (this->name);
}

int         Bureaucrat::getGrade() const{
    return (this->grade);
}

void        Bureaucrat::degrade(){
    if (this->grade >= 150)
    {
        std::string errorMessage = "Demotion for [" + this->name + "] failed cuz grade is already 150";
        print_red(errorMessage);
        throw GradeTooLowException("Error : Impossible Demotion");
    }
    this->grade++;
    std::cout << "[" << this->name << "] has been degraded to [" << (this->grade - 1) << "] --> ["<< this->grade << "]."<< std::endl;
}

void        Bureaucrat::promote(){
    if (this->grade <= 1)
    {
        std::string errorMessage = "Promotion for [" + this->name + "] failed cuz grade is already 1";
        throw GradeTooHighException(errorMessage.c_str());
    }
    this->grade--;
    std::cout << "["<< this->name << "] has been promoted to [" << (this->grade + 1) << "] --> ["<< this->grade << "]."<< std::endl;
}

void        Bureaucrat::signForm(Form &form){
    if (grade > form.getRequiredGrade()){
        throw GradeTooLowException("Error : Bureaucrat couldn't sign because grade too low.");
    }
    form.setIsSigned(1);
    form.setSignedBy(name);
    if (form.getIsSigned())
        print_blue("[" + this->name + "] signed [" + form.getName() + "].");
    else
        print_red("[" + this->name + "] couldn't signed [" + form.getName() + "] because the grade is too low.");
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs){
    o << "-------PRINT BUREAUCRAT--------" << std::endl;
    o << "[" << rhs.getName() << "] is grade [" << rhs.getGrade() << "]" << std::endl;
    o << "-------------------------------" << std::endl;
    return (o);
}

