/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:17:04 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 19:02:50 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	BitcoinExchange	btcex;

	if (ac != 2)
		std::cout << "Error: could not open file." << std::endl;
	else
	{
		try
		{
			BitcoinExchange::parseDataBase("./cpp_09/data.csv", btcex);
		}
		catch (const BitcoinExchange::ErrorMsg &e)
		{
			std::cout << e.what() << std::endl;
			return (1);
		}
		try
		{
			btcex.calculateInput(av[1]);
		}
		catch (const BitcoinExchange::ErrorMsg &e)
		{
			std::cout << e.what() << std::endl;
			return (1);
		}
	}
	return (0);
}