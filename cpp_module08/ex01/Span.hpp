/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:11:50 by hyujung           #+#    #+#             */
/*   Updated: 2023/02/12 11:57:59 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
# define SPAN_H
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include "printColor.hpp"
# include <climits>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	v;

	public:
		Span(void);
		Span(unsigned int N);
		~Span(void);
		void	addNumber(int const num);
        void    addNumber(unsigned int num, time_t seed);
		int		shortestSpan(void);
		int		longestSpan(void);
        void    printSpan(void);
        unsigned int    getSize(void) const;
        std::vector<int>    getVec(void) const;
    
    Span& operator=(const Span& span);

    class errorMessage : public std::exception
    {
        private:
            const char *message;
        public:
            explicit errorMessage(const char * message);
            virtual const char *what() const throw();
    };
		
};

#endif