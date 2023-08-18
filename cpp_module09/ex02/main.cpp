/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:01:35 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 19:12:11 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

bool contains(char *str, char c) {
	for (int i = 0; str && str[i]; ++i) {
		if (str[i] == c) return true;
	}
	return false;
}



int main(int ac, char **av) {
	PmergeMe pm = PmergeMe();

	try
	{
		if (ac == 1)
			throw PmergeMe::ErrorMsg("Error");
		pm.vectorMergeInsert(ac, av);
		pm.dequeMergeInsert(ac, av);
	}
	catch (PmergeMe::ErrorMsg &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	pm.printResults();
	return 0;
}
