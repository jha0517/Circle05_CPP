/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:14:34 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/10 19:36:03 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printColor.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    print_green("Copy Constructor : Form b(a);");
    {
        Form a("A", 2, 1);
        {
            try{
                Form b(a);
                std::cout << b << std::endl;
            }
            catch(std::exception &a){
                print_red(a.what());
            }
        }
        std::cout << a << std::endl;
    }
    print_green("Assignement Constructor : b = a;");
    {
        Form a("A", 2, 1);
        {
            Form b;
            try{
                b = a;
            }
            catch(std::exception &a){
                print_red(a.what());
            }
            std::cout << b << std::endl;
        }
        std::cout << a << std::endl;
    }
    Bureaucrat  newbie("Newbie", 150);
    Form        basicForm("BasicForm", 149, 145);

    {
        try
        {
            print_green("1.1 Form tooLowbasicForm('tooLowbasicForm', 151, 150);");
            Form        tooLowbasicForm("tooLowbasicForm", 151, 150);
        }
        catch (std::exception &e)
        {
            print_red(e.what());
        }
    }
    {
        try
        {
            print_green("1.2 Form tooHighbasicForm('tooLowbasicForm', 150, 0);");
            Form        tooHighbasicForm("tooLowbasicForm", 150, 0);
        }
        catch (std::exception &e)
        {
            print_red(e.what());
        }
    }
    try{
        print_green("2. basicForm.beSigned(newbie);");
        std::cout << basicForm;
        basicForm.beSigned(newbie);
    }
    catch (std::exception &e)
    {
        print_red(e.what());
    }
    try{
        print_green("3. basicForm.beSigned(newbie); // after promotion");
        newbie.promote();
        basicForm.beSigned(newbie);
        // newbie.signForm(basicForm);
    }

    catch (std::exception &e)
    {
        print_red(e.what());
    }
    std::cout << basicForm << std::endl;
    try{
        print_green("4. SIGN AGAIN : basicForm.beSigned(newbie);");
        basicForm.beSigned(newbie);
    }
    catch (std::exception &e)
    {
        print_red(e.what());
    }
}