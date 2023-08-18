/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:01:37 by hyujung           #+#    #+#             */
/*   Updated: 2023/04/10 19:12:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::ErrorMsg::ErrorMsg(const char *message) : message(message) {}
const char *PmergeMe::ErrorMsg::what() const throw(){ return message; }

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) {
  deq = src.deq;
  vec = src.vec;
}
PmergeMe::~PmergeMe(){}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  deq = rhs.deq;
  vec = rhs.vec;
	return (*this);
}

std::string PmergeMe::parseToString(int ac, char **av) {
	std::string	ret;

	for (int i = 1; i < ac; i++)
	{
		ret += av[i];
		if (i != ac - 1)
		{
			ret += " ";
		}
	}
	for (size_t i = 0; i < ret.length(); i++)
		if (!std::isspace(ret[i]) && !std::isdigit(ret[i]))
			throw PmergeMe::ErrorMsg("Error");
	return (ret);
}

void    PmergeMe::algorithmFordJohnson(std::vector<int> &sequence_vec)
{
    if (sequence_vec.size() < 2)
        return;
    int mediane = sequence_vec.size() / 2;
    std::vector<int> first(sequence_vec.begin(), sequence_vec.begin() + mediane);
    std::vector<int> second(sequence_vec.begin() + mediane, sequence_vec.end());

    algorithmFordJohnson(first);
    algorithmFordJohnson(second);

    size_t i, j, k;

    i = j = k = 0;
    while(i < first.size() && j < second.size())
    {
        if (first[i] < second[j])
            sequence_vec[k++] = first[i++];
        else
            sequence_vec[k++] = second[j++];
    }
    while (i < first.size())
        sequence_vec[k++] = first[i++];
    while(j < second.size())
        sequence_vec[k++] = second[j++];
}

void    PmergeMe::algorithmFordJohnson(std::deque<int> &sequence_deque)
{
    if (sequence_deque.size() < 2)
        return;
    int mediane = sequence_deque.size() / 2;


    std::deque<int> first(sequence_deque.begin(), sequence_deque.begin() + mediane);
    std::deque<int> second(sequence_deque.begin() + mediane, sequence_deque.end());

    algorithmFordJohnson(first);
    algorithmFordJohnson(second);

    size_t i, j, k;

    i = j = k = 0;
    while(i < first.size() && j < second.size())
    {
        if (first[i] < second[j])
            sequence_deque[k++] = first[i++];
        else
            sequence_deque[k++] = second[j++];
    }
    while (i < first.size())
        sequence_deque[k++] = first[i++];
    while(j < second.size())
        sequence_deque[k++] = second[j++];
}

void	PmergeMe::vectorMergeInsert(int ac, char **av){
	clock_t start;
	clock_t end;
	int tmp;

	start = clock();
	std::stringstream ss(parseToString(ac, av));
	before = ss.str();
	while (ss >> tmp)
		this->vec.push_back(tmp);
    algorithmFordJohnson(vec);
	end = clock();
	timeVec = static_cast<double>(end - start) / 1000;
}

void	PmergeMe::dequeMergeInsert(int ac, char **av){
	clock_t start;
	clock_t end;
	int tmp;
	
	start = clock();
	std::stringstream ss(parseToString(ac, av));
	before = ss.str();
	while (ss >> tmp)
		this->deq.push_back(tmp);
    algorithmFordJohnson(deq);
	end = clock();
	timeDeq = static_cast<double>(end - start) / 1000;
}

void	PmergeMe::printResults() const{
	
	std::cout << "Before: " << this->before << std::endl;
	std::cout << "After: ";
	this->printVector();
	// this->printDeq();

	std::cout << "[Performance]" << std::endl;
	std::cout << "Time to process a range of "
		<< this->vec.size() << " elements with <std::vector> :\t"
		<< timeVec << " ms" << std::endl;
	std::cout << "Time to process a range of "
		<< this->vec.size() << " elements with <std::deque>   :\t"
		<< timeDeq << " ms" << std::endl;
}

void PmergeMe::printVector()  const{
	int size = this->vec.size();
	for(int i = 0; i < size; ++i) {
		std::cout << this->vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeq()  const{
	for(std::deque<int>::const_iterator it = this->deq.begin(); it != this->deq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}