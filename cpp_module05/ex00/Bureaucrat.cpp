/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:46:32 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/09 20:06:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("DefaultGuy"), grade(150)
{
    std::cout << "Default Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const n, int const g) : name(n), grade(g)
{
    if (g < 1)
        throw Bureaucrat::GradeTooHighException();
    if (g > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout <<"[" << this->name << "] grade [" << this->grade <<"] Bureaucrat Constructor Called" << std::endl;
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : name(rhs.getName()), grade(rhs.getGrade())
{
    std::cout << "Copy Bureaucrat Constructor Called" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &rhs){
    std::cout << "Assignement Bureaucrat Constructor Called" << std::endl;
    if (this != &rhs){
        grade = rhs.getGrade();
        throw Bureaucrat::CanNotChangeConst();
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
        print_red("Demotion for [" + this->name + "] failed.");
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
    std::cout << "[" << this->name << "] has been degraded to [" << (this->grade - 1) << "] --> ["<< this->grade << "]."<< std::endl;
}

void        Bureaucrat::promote(){
    if (this->grade <= 1)
    {
        print_red("Promotion for [" + this->name + "] failed.");
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
    std::cout << "["<< this->name << "] has been promoted to [" << (this->grade + 1) << "] --> ["<< this->grade << "]."<< std::endl;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs){
    o << "-------PRINT BUREAUCRAT--------" << std::endl;
    o << "[" << rhs.getName() << "] is grade [" << rhs.getGrade() << "]" << std::endl;
    o << "-------------------------------" << std::endl;
    return (o);
}