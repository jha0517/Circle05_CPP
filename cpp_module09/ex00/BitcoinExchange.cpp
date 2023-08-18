/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 12:17:00 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 19:41:13 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::ErrorMsg::ErrorMsg(const char *message) : message(message) {}
const char *BitcoinExchange::ErrorMsg::what() const throw(){ return message; }

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		this->data = rhs.data;
	return (*this);
}

float stringToFloat(std::string data)
{
	std::istringstream ss(data);
	float f;
	ss >> f;
	return (f);
}

bool BitcoinExchange::checkDateFormat(const std::string &date)
{
    std::istringstream iss(date);
    int year, month, day;
    char delim1, delim2;

    if (iss >> year >> delim1 >> month >> delim2 >> day &&
        delim1 == '-' && delim2 == '-' &&
        year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31) {
			if (month == 2 && day >= 30)
				return false;
        return true;
    }
    return false;
}

void BitcoinExchange::parseDataBase(const char *priceDataFileName, BitcoinExchange &btcex)
{
	std::ifstream priceDataFile(priceDataFileName);
	std::string line;
	
	// error check
	if (!priceDataFile)
		throw BitcoinExchange::ErrorMsg("Error: file Not found or Access Error.");
	
	std::getline(priceDataFile, line);
	if (line != "date,exchange_rate")
	{
		priceDataFile.close();
		throw BitcoinExchange::ErrorMsg("Error: In CSV, incorrect Header.");
	}

	// read
	while (std::getline(priceDataFile, line))
	{
		std::istringstream iss(line);
		std::string date, priceStr;

		if (std::getline(iss, date, ',') && std::getline(iss, priceStr))
		{
			if (!btcex.checkDateFormat(date))
			{
				priceDataFile.close();
				throw BitcoinExchange::ErrorMsg("Error: In CSV, incorrect date.");
			}
			// std::cout << date << ", price : " << priceStr << std::endl;
			btcex.data[date] = stringToFloat(priceStr);
		}
	}
	priceDataFile.close();
}

std::map<std::string, float>::iterator BitcoinExchange::findClosestDate(std::string const &date)
{
	if (this->data.lower_bound(date) == this->data.end())
	{
		return (--this->data.end());
	}
	if (this->data.lower_bound(date)->first == date)
		return (data.lower_bound(date));
	return (--data.lower_bound(date));
}

void BitcoinExchange::printPrices(std::string const &date, float const &quantity)
{

	if (quantity < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (quantity > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else if (this->data.lower_bound(date) == this->data.begin())
	{
		std::cout << "Error: before Bitcoin Existed." << std::endl;
	}
	else
	{
		// std::cout << date << " => " << quantity << " = "
		// 		  << this->findClosestDate(date)->second * quantity << "recent past date in DB: " << this->findClosestDate(date)->first << std::endl;
		std::cout << date << " => " << quantity << " = "
				  << this->findClosestDate(date)->second * quantity << std::endl;
	}
}
 
bool isNumber(const std::string& s)
{
	size_t pos = s.find_first_not_of("0123456789 .-");
	if (pos !=  std::string::npos)
		return (false);
	std::string::difference_type n = std::count(s.begin(), s.end(), '.');
	if (n > 1)
		return (false);
	if (s.length() == 1 && n == 1)
		return (false);
    return true;
 }
 
void	BitcoinExchange::calculateInput(const char *inputFile){
	std::ifstream inputFileData(inputFile);
	std::string line;

	if (!inputFileData)
		throw BitcoinExchange::ErrorMsg("Error: file Not found or Access Error.");

	std::getline(inputFileData, line);
	if (line != "date | value")
	{
		inputFileData.close();
		throw BitcoinExchange::ErrorMsg("Error: In input file, incorrect date.");
	}

	while (std::getline(inputFileData, line))
	{
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		std::istringstream iss(line);
		std::string date, value;

		if (line.length() == 0)
			continue;
		if (line.find("|") == std::string::npos)
		{
			std::cout << "Error: bad input => "<< line << std::endl;
			// break;	
		}
		else if (std::getline(iss, date, '|'))
		{
			if (date.empty())
				std::cout << "Error: In input file, missing date" << std::endl;
			else if (!this->checkDateFormat(date))
				std::cout << "Error: bad input => "<< date << std::endl;
			
			if (this->checkDateFormat(date) && std::getline(iss, value))
			{
				if (!isNumber(value))
				{
					std::cout << "Error: not number => ";
					std::cout << value << std::endl;
				}
				else
					printPrices(date, stringToFloat(value));
			}
		}
		else if (value.empty() && this->checkDateFormat(date))
			std::cout << "Error: In input file, missing value" << std::endl;
	}
	inputFileData.close();
}