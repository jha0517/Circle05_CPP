/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:04:28 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/12 17:34:39 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Currently pushed : ";
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size : ";
		std::cout << mstack.size() << std::endl;
		mstack.push(3); mstack.push(5); mstack.push(737); //[...] mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
		std::stack<int> s(mstack);
	}
	std::cout << "----------------------------" << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "Currently pushed : ";
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "size : ";
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3); mstack.push_back(5); mstack.push_back(737); //[...] mstack.push(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
		++it; }
	}
	std::cout << "----------------------------" << std::endl;
    {
        MutantStack<double> mstack;
        mstack.push(45.5);
        mstack.push(34.22);
        mstack.push(2.23);
        mstack.push(1.0);
        mstack.push(-34.3);
        const MutantStack<double> consti(mstack);
        {
            MutantStack<double>::const_iterator it = consti.begin();
            MutantStack<double>::const_iterator ite = consti.end();

            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
        }
	std::cout << "----------------------------" << std::endl;
        MutantStack<double> i(mstack);
        {
            MutantStack<double>::const_iterator it = i.begin();
            MutantStack<double>::const_iterator ite = i.end();

            while (it != ite)
            {
                std::cout << *it << std::endl;
                ++it;
            }
        }
    }
}