/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:14:34 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/09 18:48:58 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "printColor.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        print_red("--------------------------- C05 EX02 MAIN START ------------------------------");
        print_green("------------------------- TEST COPY CONSTRUCTOR ----------------------------");
        ShrubberyCreationForm a("target");
        std::cout << a;
        {
            print_green(". creating new instance");
            ShrubberyCreationForm b(a);
            print_green(". after copy");
            std::cout << b;
        }
    }
    {
        print_green("------------------------- ASSIGNEMENT COPY TEST ----------------------------");
        ShrubberyCreationForm a("TO_BE_REPLACE");
        std::cout << a;
        {
            print_green(". creating new instance");
            ShrubberyCreationForm b("GOOD_COPY");
            std::cout << b;
            print_green(". assignement");
            a = b;
            print_green(". after copy");
            std::cout << a;
        }
    }
    print_green("------------------------- SIGNING / EXECUTING FORM TEST ----------------------------");
    {
        print_green("        << ShrubberyCreationForm TEST >>");
        Bureaucrat manager("Manager", 138);
        Bureaucrat intern("Intern", 146);
        Bureaucrat CEO("CEO", 1);
        ShrubberyCreationForm form("v1");

        std::cout << std::endl << form;


        print_green(". execute without signature");
        try{CEO.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}
        
        print_green(". grade too low to sign");
        try{intern.signForm(form);}
        catch(std::exception &a){print_red(a.what());}

        intern.promote();
        print_green(". sign");
        try{intern.signForm(form);}
        catch(std::exception &a){print_red(a.what());}
        std::cout << std::endl << form;

        print_green(". grade too low to execute");
        try{manager.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}

        manager.promote();
        print_green(". execute");
        try{manager.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}
    }
    {
        print_green("        << RobotomyRequestForm TEST >>");
        Bureaucrat executive("Executive", 46);
        Bureaucrat manager("Manager", 73);
        RobotomyRequestForm form("v1");

        std::cout << std::endl << form;
        print_green(". grade too low to sign");
        try{manager.signForm(form);}
        catch(std::exception &a){print_red(a.what());}

        manager.promote();
        print_green(". sign");
        try{manager.signForm(form);}
        catch(std::exception &a){print_red(a.what());}
        std::cout << std::endl << form;

        print_green(". grade too low to execute");
        try{executive.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}

        executive.promote();
        print_green(". execute");
        try{executive.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}
    }
    {
        print_green("        << PresidentialPardonForm TEST >>");
        Bureaucrat ceo("CEO", 6);
        Bureaucrat executive("Executive", 26);
        PresidentialPardonForm form("Target");

        std::cout << std::endl << form;
        print_green(". grade too low to sign");
        try{executive.signForm(form);}
        catch(std::exception &a){print_red(a.what());}

        executive.promote();
        print_green(". sign");
        try{executive.signForm(form);}
        catch(std::exception &a){print_red(a.what());}
        std::cout << std::endl << form;

        print_green(". grade too low to execute");
        try{ceo.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}

        ceo.promote();
        print_green(". execute");
        try{ceo.executeForm(form);}
        catch(std::exception &a){print_red(a.what());}
    }

    return (0);
}