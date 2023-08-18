/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:11:43 by hyujung           #+#    #+#             */
/*   Updated: 2023/02/12 11:51:59 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span s(10);

	try{
		s.addNumber(1);
		s.addNumber(3);
		s.addNumber(8);
		s.addNumber(0);
		s.addNumber(-10);
		s.addNumber(2);
		s.addNumber(-1);
		s.printSpan();
		std::cout << "Shortest Span : " << s.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << s.longestSpan();
	}
	catch(std::exception &e){print_red(e.what());}
    std::cout << std::endl << "------------" << std::endl;
    try {
		Span a(10);
		a.printSpan();
		a = s;
		a.printSpan();
    }
	catch(std::exception &e){print_red(e.what());}
    std::cout << "------------\n";
	try{
		Span s(10000);
		s.addNumber(10000, time(NULL));
		// s.printSpan();
		std::cout << "Shortest Span : " << s.shortestSpan() << std::endl;
		std::cout << "Longest Span : " << s.longestSpan() << std::endl;
	}
	catch(std::exception &e){print_red(e.what());}
}