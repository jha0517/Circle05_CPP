/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:15:22 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 23:25:24 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	std::srand(std::time(NULL) + std::rand());
	switch (std::rand() % 3)
	{
		case 0:
			return (new A());
			break;
		case 1:
			return (new B());
			break;
		case 2:
			return (new C());
			break;
		default :
			std::cout << "something went wrong."<< std::endl;
	}
	return (NULL);
}

void	identify(Base* p)
{
	A *a = dynamic_cast<A *>(p);
	if (a)
		std::cout << "A" << std::endl;
	B *b = dynamic_cast<B *>(p);
	if (b)
		std::cout << "B" << std::endl;
	C *c = dynamic_cast<C *>(p);
	if (c)
		std::cout << "C" << std::endl;

}

void	identify(Base& p)
{
	try{
		A & a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)a;
		}
	catch(std::exception &bc){}
	try{
		B & b = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)b;
		}
	catch(std::exception &bc){}
	try{
		C & c = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)c;
		}
	catch(std::exception &bc){}
}

int	main()
{
	{
		Base *p;
		p = generate();
		identify(p); //first
		identify(*p); //second
		delete p;
	}
	{
		Base *p;
		p = generate();
		identify(p); //first
		identify(*p); //second
		delete p;
	}
}