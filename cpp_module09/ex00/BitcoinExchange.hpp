/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:17:02 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 18:52:36 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <stdexcept>
# include <map>
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <algorithm>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	data;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &assign);

		void	    calculateInput(const char *filename);
		static void	parseDataBase(const char *filename, BitcoinExchange &btcex);
        bool        checkDateFormat(const std::string &date);
		void		printPrices(std::string const &date, float const &quantity);
		std::map<std::string, float>::iterator findClosestDate(std::string const &date);

    class ErrorMsg : public std::exception
    {
        private:
            const char *message;
        public:
            explicit ErrorMsg(const char *message);
            virtual const char *what() const throw();
    };
};

#endif
