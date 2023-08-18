/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:04:20 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/12 17:19:15 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <iostream>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	MutantStack<T>(void){}
	MutantStack<T>(const MutantStack<T> & mutant) : std::stack<T>(mutant) {}
	~MutantStack<T>(void){}
	MutantStack<T> & operator=(const MutantStack<T> & mutant)
	{
		this->c = mutant.c;
		return *this;
	}
	iterator begin() {return this->c.begin();}
	iterator end() {return this->c.end();}
	const_iterator begin() const {return this->c.begin();}
	const_iterator end() const {return this->c.end();}
};

#endif
