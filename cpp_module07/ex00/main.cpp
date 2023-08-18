/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:28:04 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/11 20:33:26 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "printColor.hpp"
#include "whatever.hpp"

int	main(void)
{
	{
		int	a = 1;
		int	b = 2;		
		print_green("------ Max ---------");
		print_blue(". int");
		std::cout << max<int>(a, b) << std::endl;
		std::cout << max(a, b) << std::endl;
	}
	{
		float	a = 0.4f;
		float	b = 0.3f;

		print_blue(". float");
		std::cout << max<float>(a, b) << std::endl;
		std::cout << max(a, b) << std::endl;
	}
	{
		double	a = 0.4123;
		double	b = 0.4124;

		print_blue(". double");
		std::cout << max<double>(a, b) << std::endl;
		std::cout << max(a, b) << std::endl;
	}
	{
		std::string	a = "aa";
		std::string	b = "ab";

		print_blue(". std::string");
		std::cout << ::max(a, b) << std::endl;
	}
	{
		int	a = 1;
		int	b = 2;		
		print_green("------ Min ---------");
		print_blue(". int");
		std::cout << min<int>(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	{
		float	a = 0.4f;
		float	b = 0.3f;

		print_blue(". float");
		std::cout << min<float>(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	{
		double	a = 0.4123;
		double	b = 0.4124;

		print_blue(". double");
		std::cout << min<double>(a, b) << std::endl;
		std::cout << min(a, b) << std::endl;
	}
	{
		char	a = 'a';
		char	b = 'b';

		print_blue(". char");
		std::cout << min<char>(a, b) << std::endl;
		std::cout << ::min(a, b) << std::endl;
	}
	{
		std::string	a = "a";
		std::string	b = "b";

		print_blue(". std::string");
		std::cout << ::min(a, b) << std::endl;
	}
	{
		int	a = 1;
		int	b = 2;		
		print_green("------ Swap ---------");
		print_blue(". int");
		std::cout << "REF a : " << a << ", b : " << b << std::endl;
		swap<int>(a, b);
		std::cout << "SWAP a : " << a << ", b : " << b << std::endl;
		swap(a, b);
		std::cout << "SWAP a : " << a << ", b : " << b << std::endl;
	}
	{
		float	a = 0.4f;
		float	b = 5.3f;

		print_blue(". float");
		std::cout << "REF a : " << a << ", b : " << b << std::endl;
		swap<float>(a, b);
		std::cout << "SWAP a : " << a << ", b : " << b << std::endl;
		swap(a, b);
		std::cout << "SWAP a : " << a << ", b : " << b << std::endl;
	}
	{
		double	a = 0.4123;
		double	b = 1.2345;
		print_blue(". double");
		std::cout << "REF a : " << a << ", b : " << b << std::endl;
		swap<double>(a, b);
		std::cout << "SWAP a : " << a << ", b : " << b << std::endl;
		swap(a, b);
		std::cout << "SWAP a : " << a << ", b : " << b << std::endl;
	}
	{
		print_green("------ MAIN FROM SUJECT ---------");
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		std::cout << std::endl;
		print_blue("------ EXPECTED OUTPUT ---------");
		std::cout << "a = 3, b = 2\nmin(a, b) = 2\nmax(a, b) = 3\nc = chaine2, d = chaine1\nmin(c, d) = chaine1\nmax(c, d) = chaine2\n";
	}

}
