/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:37 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/11 20:36:25 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    {
        print_green("-------- INT Array --------");
        Array<int> c;
        Array<int> a(4);
        Array<int> b(5);
        int  d = 1000;
        a[0] = 1;
        a[0] = 100;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        b[0] = 1;
        b[1] = 2;
        b[2] = 3;
        b[3] = 4;
        b[4] = d;
        try{a[4] = 4;}
        catch (std::exception &a){print_red(a.what());}
        std::cout << a[0] << std::endl;
        std::cout << a[1] << std::endl;
        std::cout << a[2] << std::endl;
        std::cout << a[3] << std::endl;
        try{std::cout << a[4] << std::endl;}
        catch (std::exception &a){print_red(a.what());}
        a = b;
        std::cout << a.size() << std::endl;
        try{std::cout << a[4] << std::endl;}
        catch (std::exception &a){print_red(a.what());}
    }
    {
        print_green("-------- STRING Array --------");
        Array<std::string> c;
        Array<std::string> a(4);
        Array<std::string> b(5);
        std::string  d = "YOOOOOOOOOO";
        a[0] = "1";
        a[1] = "2";
        a[2] = "3";
        a[3] = "4";
        b[0] = "1";
        b[1] = "2";
        b[2] = "3";
        b[3] = "4";
        b[4] = d;
        try{a[4] = 4;}
        catch (std::exception &a){print_red(a.what());}
        std::cout << a[0] << std::endl;
        std::cout << a[1] << std::endl;
        std::cout << a[2] << std::endl;
        std::cout << a[3] << std::endl;
        try{std::cout << a[4] << std::endl;}
        catch (std::exception &a){print_red(a.what());}
        a = b;
        std::cout << a.size() << std::endl;
        try{std::cout << a[4] << std::endl;}
        catch (std::exception &a){print_red(a.what());}
    }
}

// #include "Array.hpp"
// #include <cstdlib>
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = std::rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

