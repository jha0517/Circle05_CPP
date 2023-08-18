/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 08:35:29 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 20:46:47 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.hpp"

int	main()
{
	Data d;
	Data *d_ptr1;
	Data *d_ptr2;
	uintptr_t	voidptr;

	d.i = 1;
	d_ptr1 = &d;
	std::cout << "before : "<< d_ptr1->i << std::endl;
	voidptr = serialize(d_ptr1);
	d_ptr2 = deserialize(voidptr);
	std::cout << "after : "<< d_ptr2->i << std::endl;

}