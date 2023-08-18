/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:49:17 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 20:44:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int isDigits(std::string str, int checkDecim)
{
	if (!checkDecim)
		return (str.find_first_not_of("0123456789-") == std::string::npos);
	else if (checkDecim == 2)
		return (str.find_first_not_of("0123456789-.") == std::string::npos);
	return (str.find_first_not_of("0123456789.-f") == std::string::npos);
}

int	hasEndingF(std::string &str)
{
	if (str.rfind("f") == str.find("f") && str.find("f") == str.length() -1)
		return (1);
	return (0);
}

int	hasLessThanTwoNeg(const std::string &str)
{
	if (str.find("-") == std::string::npos)
		return (1);
	if (str.rfind("-") == 0 && str.find("-") == 0)
		return (1);
	return (0);
}

int	hasOnePoint(const std::string &str)
{
	std::size_t	found;
	found = str.find(".");
	if (found == std::string::npos)
		return (0);
	found = str.find(".", found + 1);
	if (found != std::string::npos)
		return (0);
	return (1);
}

int	getType(char const *av)
{
	std::string s(av);
	std::string sub = s.substr(1, s.length());
	if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf" || s == "-inff" || s == "+inff" || s == "inff")
		return (T_SPECIAL);
	if (s.length() == 1 && !isDigits(s, 0))
	{
		std::istringstream	ss_int(s);
		char	n;
		ss_int >> n;
		if (isprint(static_cast<int>(n)))
			return (T_CHAR);
		return (0);
	}
	else if (!hasOnePoint(s) && isDigits(s, 0) && hasLessThanTwoNeg(s))
	{
		char		*tmp2;
		const long	i = std::strtol(av, &tmp2, 10);
		if (i > std::numeric_limits<int>::max() || (i < std::numeric_limits<int>::min()))
			return (0);
		return (T_INT);
	}
	else if (hasOnePoint(s) && hasLessThanTwoNeg(s))
	{
		if (hasEndingF(s) && isDigits(s, 1))
		{
			char		*ptr;
			double i = strtod(s.c_str(), &ptr);	
			if (i > std::numeric_limits<float>::max() || (i < std::numeric_limits<float>::min()))
				return (0);

			return (T_FLOAT);
		}
		else if (isDigits(s, 2))
			return (T_DOUBLE);
	}
	return (0);
}

void	print_type(int type)
{
	std::cout << std::endl;
	switch (type)
	{
        case 1 :
            std::cout << "TYPE IS FLOAT " << std::endl;
			break;
        case 2 :
            std::cout << "TYPE IS INT " << std::endl;
			break;
        case 3 :
            std::cout << "TYPE IS CHAR " << std::endl;
			break;
        case 4 :
            std::cout << "TYPE IS DOUBLE " << std::endl;
			break;
        case 5 :
            std::cout << "TYPE IS SPECIAL " << std::endl;
			break;
        default: {
            std::cout << "Unknown Input" << std::endl;
            break;
        }
	}
}
int	main(int ac, char const **av)
{
	int			type;
	Conversion	conv;
	char		*ptr;

	ptr = NULL;
	if (ac != 2){
		std::cout << "Need one parameter.";
		return (0);
	}
	type = getType(av[1]);
	if (!type)
		return (std::cout << "Invalid input. Acceptable [char], [int], [float], [double]",0);
	if (type == T_DOUBLE || T_SPECIAL)
		conv.cast(strtod(av[1], &ptr));
	if (type == T_FLOAT)
		conv.cast(static_cast<float>(strtod(av[1], &ptr)));
	if (type == T_CHAR)
		conv.cast(av[1][0]);
	if (type == T_INT)
		conv.cast(static_cast<int>(strtod(av[1], &ptr)));
	conv.print();
	return (0);
}