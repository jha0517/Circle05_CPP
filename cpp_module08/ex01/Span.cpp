/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 00:11:48 by hyujung           #+#    #+#             */
/*   Updated: 2023/02/12 11:50:39 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::errorMessage::errorMessage(const char *message) : message(message) {}
const char *Span::errorMessage::what() const throw(){ return message; }

Span::Span(void) : _N(0), v(0) {}
Span::Span(unsigned int N): _N(N) {}
Span::~Span(void) {}
void	Span::addNumber(int const num) {
	std::vector<int>::iterator it;

	it = std::find(v.begin(), v.end(), num);
	if (it != v.end())
		throw errorMessage("Error : num already in the vector");
	if (_N <= v.size())
		throw errorMessage("Error : Can't add, already Maxed");
	v.push_back(num);
}

void printVector(std::vector <int> &a) {
	std::cout << "The elements are : ";
	std::vector<int>::iterator it;
	for(it = a.begin(); it != a.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void    Span::printSpan(void) {
	printVector(v);
}

int		Span::shortestSpan(void) {
	if (v.size() == 0)
		throw errorMessage("Error : Empty for now. add numbers.");
	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	// printVector(tmp);
	std::vector<int>::iterator it;
	unsigned int shortestSpan = INT_MAX;
	for(it = tmp.begin(); it != tmp.end()-1; it++)
	{
		unsigned int a = abs(abs(*it) - abs(*it+1));
		if (shortestSpan > a){shortestSpan = a;}
	}
	return (shortestSpan);	
}

int		Span::longestSpan(void) {
	if (v.size() == 0)
		throw errorMessage("Error : Empty for now. add numbers.");
	std::vector<int> tmp(v);
	std::sort(tmp.begin(), tmp.end());
	// printVector(tmp);
	return (abs(tmp.back()) + abs(tmp.front()));
}
unsigned int    Span::getSize(void)const{return (_N);}
std::vector<int>    Span::getVec(void)const{return (v);}

Span& Span::operator=(const Span& span)
{
    _N = span.getSize();
    v = span.getVec();
    return *this;
}

void	Span::addNumber(unsigned int num, time_t seed)
{
	srand(seed);
	for (size_t i = 0; i < num; i++)
	{
		try	{addNumber(rand());}
		catch(const std::exception& e){print_red(e.what());}
	}
}