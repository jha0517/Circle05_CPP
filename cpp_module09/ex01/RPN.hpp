/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:23:00 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 08:42:56 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
	public:
		RPN();
		RPN(const RPN &copy);
		~RPN();
		RPN & operator=(const RPN &assign);
		int calculate(const std::string &str);

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