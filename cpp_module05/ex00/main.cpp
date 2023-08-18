/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:14:34 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/09 17:51:13 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    print_green("Copy Constructor : Bureaucrat b(a);");
    {
        Bureaucrat a("A", 1);
        {
            try{
                Bureaucrat b(a);
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
        Bureaucrat a("A", 1);
        {
            Bureaucrat b;
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
    Bureaucrat tom("Tom", 4);
    Bureaucrat anna("Anna", 3);

    print_green("try : Create and Promote Bureaucrat tom('Tom', 4);");
    {
        try{
            Bureaucrat tom("Tom", 4);
            tom.promote();
            std::cout << tom << std::endl;
        }
        catch (std::exception &a){
            print_red(a.what());
        }
    }
    std::cout << std::endl;

    print_green("try : Create and Degrade Bureaucrat tom('Tom', 4);");
    {
        try{
            Bureaucrat tom("Tom", 4);
            tom.degrade();
            std::cout << tom << std::endl;
        }
        catch (std::exception &a){
            print_red(a.what());
        }
    }
    std::cout << std::endl;

    print_green("try : Bureaucrat tom('Tom', 151);");
    {
        try{
            Bureaucrat tom("Tom", 151);
        }
        catch (std::exception &a){
            print_red(a.what());
        }
    }
    std::cout << std::endl;

    print_green("try : Promote Bureaucrat tom('Tom', 1);");
    {
        Bureaucrat tom("Tom", 1);
        try{
            tom.promote();
        }
        catch (std::exception &a){
            print_red(a.what());
            std::cout << tom;
        }
    }

    std::cout << std::endl;

    print_green("try : Degrading Bureaucrat tom('Tom', 150);");
    {
        Bureaucrat tom("Tom", 150);
        try{
            tom.degrade();
        }
        catch (std::exception &a){
            std::cout << tom;
            print_red(a.what());
        }
    }
}