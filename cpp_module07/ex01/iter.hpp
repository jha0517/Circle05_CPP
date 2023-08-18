/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:44:57 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/11 12:45:49 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T* array, std::size_t n, void (*f)(T&))
{
    for (std::size_t i = 0; i < n; ++i)
    {
        f(array[i]);
    }
}

template <typename T>
void printElement(T& a)
{
    std::cout << a << std::endl;
}

#endif