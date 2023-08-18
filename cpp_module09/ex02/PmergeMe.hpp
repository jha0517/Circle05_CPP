/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:01:40 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 19:12:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <cstdlib>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <sstream>

class PmergeMe {
	private:
		std::vector<int> vec;
		std::deque<int> deq;
		double	timeDeq;
		double	timeVec;
		std::string before;


	public:
		PmergeMe();
		PmergeMe(const PmergeMe &inst);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe &rhs);
		void	vectorMergeInsert(int ac, char **av);
		void	dequeMergeInsert(int ac, char **av);
		void	printResults() const;
		void 	printVector() const;
		void 	printDeq() const;

		std::string	parseToString(int ac, char **av);


		void	algorithmFordJohnson(std::vector<int> &vec);
		void	algorithmFordJohnson(std::deque<int> &deq);

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