/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:54:39 by hyujung           #+#    #+#             */
/*   Updated: 2023/02/10 19:04:54 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    const int a[] = {1, 0, 2, -1, 3};

    {
        std::vector<int> vec(a, a + 5);
        const int v = 0;
        std::cout << "v = " << v << '\n';
        std::vector<int>::iterator it = easyfind(vec, v);
        if (it != vec.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    std::cout << "------------\n";
    {
        std::vector<int> vec(a, a + 5);
        const int v = 10;
        std::cout << "v = " << v << '\n';
        std::vector<int>::iterator it = easyfind(vec, v);
        if (it != vec.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    std::cout << "------------\n";
    {
        const std::vector<int> vec(a, a + 5);
        const int v = 2;
        std::cout << "v = " << v << '\n';
        std::vector<int>::const_iterator it = easyfind(vec, v);
        if (it != vec.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
    std::cout << "------------\n";
    {
        std::list<int> lst(a, a + 5);
        const int v = 2;
        std::cout << "v = " << v << '\n';
        const std::list<int>::const_iterator it = easyfind(lst, v);
        if (it != lst.end())
        {
            std::cout << "find -> " << *it << std::endl;
        }
        else
        {
            std::cout << "not found" << std::endl;
        }
    }
}