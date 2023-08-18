/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:35:04 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/09 18:41:53 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <string>

int	main(int ac, char **av)
{
	RPN rpn;
	try
	{
		if (ac != 2)
			throw RPN::ErrorMsg("Error");
		std::cout << rpn.calculate(av[1]) << std::endl;
	}
	catch (const RPN::ErrorMsg &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}
    return (0);
}
