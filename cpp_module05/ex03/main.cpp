/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:14:34 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/09 18:51:33 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "printColor.hpp"

int main()
{
    print_red("--------------------------- C05 EX03 MAIN START ------------------------------");
    print_green("------------------------- CREATE FORM TEST ----------------------------");
    Bureaucrat bru("bru", 1);
    {
        Intern me;
        
        AForm *a = me.makeForm("shrubbery request", "Boss");
        delete a;
    }
    {
        print_green("------------------------- MAIN FROM SUBJECT ----------------------------");
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            bru.signForm(*rrf);
            bru.executeForm(*rrf);
            delete rrf;
        }
    }
    return (0);
}
