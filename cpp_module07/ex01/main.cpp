/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:37 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/11 14:00:15 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "printColor.hpp"
#include <string>
#define TEST_SIZE 5
int main()
{
    {
        print_green("-------- String Array --------");
        std::string array[3] = {"string1", "string2", "string3"};
        iter(array, 3, printElement);
    }
    {
        print_green("-------- INT Array --------");
        int array[3] = {2, 1, 100};
        iter(array, 3, printElement);
    }
    {
        print_green("-------- FLOAT Array --------");
    	float array[5] = {0.1, -0.1, 0, 42, -42.0f};
        iter(array, 5, printElement);
    }
    {
        print_green("-------- Char Array --------");
    	char array[] = {'a', 'e', 'r', 'g', 'd'};
        iter(array, 5, printElement);
    }
}
