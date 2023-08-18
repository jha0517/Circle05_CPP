/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:22:57 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 17:28:32 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <algorithm>

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN()
{
}

RPN & RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
	{
		this->_stack = rhs._stack;
	}
	return (*this);
}

RPN::ErrorMsg::ErrorMsg(const char *message) : message(message) {}
const char *RPN::ErrorMsg::what() const throw(){ return message; }

void printStack(std::stack<int> s)
{
    // If stack is empty then return
    if (s.empty())
        return;
     
    int x = s.top();
 
    // Pop the top element of the stack
    s.pop();
 
    // Recursively call the function PrintStack
    printStack(s);
 
    // Print the stack element starting
    // from the bottom
    std::cout << x << " ";
 
    // Push the same element onto the stack
    // to preserve the order
    s.push(x);
}

bool is_whitespace(char c)
{
    return std::isspace(static_cast<unsigned char>(c));
}

std::string trim(const std::string& str)
{
    std::string result;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(result), is_whitespace);

    return result;
}

int RPN::calculate(const std::string &arg)
{
    int b;
    int a;
    std::string str = trim(arg);
    int i = -1;
    while (str[++i])
    {
        if (isdigit(str[i]))
            _stack.push(str[i] - '0');
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            if (_stack.size() < 2)
				throw RPN::ErrorMsg("Error: not enough operands");
            b = _stack.top();
            _stack.pop();
            a = _stack.top();
            _stack.pop();
            switch (str[i])
            {
                case '+':
                    _stack.push(a + b);
                    break;
                case '-':
                    _stack.push(a - b);
                    break;
                case '*':
                    _stack.push(a * b);
                    break;
                case '/':
                {
                    if (b == 0)
						throw RPN::ErrorMsg("Error: a division by 0 is impossible");
                    _stack.push(a / b);
                    break;

                }
            }
        }
        else
			throw RPN::ErrorMsg("Error: non authorized charcater");
    }
    if (_stack.size() != 1)
		throw RPN::ErrorMsg("Error: too many operands");
    return (_stack.top());
}
