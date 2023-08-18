/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:30:10 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 20:43:52 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion() : _precis(16), _impossible(0), _nonDisplayable(0), _overflow(0), _add("") {}
Conversion::Conversion(const Conversion &rhs){
	*this = rhs;
}
Conversion::~Conversion(){}
Conversion & Conversion::operator=(const Conversion &rhs){
	_c = rhs._c;
	_i = rhs._i;
	_d = rhs._d;
	_f = rhs._f;
	return (*this);
}

void	Conversion::cast(double d){
	_d = d;
	_f = static_cast<float>(d);
	if ((_d <= std::numeric_limits<int>::max()) && ((_d >= std::numeric_limits<int>::min())))
		_i = static_cast<int>(_d);
	else
	{
		_overflow = 1;
		_impossible = 1;
		return ;
	}
	if (_i > 31 && _i < 127)
		_c = static_cast<char>(_i);
	else if ((_i >= 0 && _i <= 31) || (_i == 127)){
		_nonDisplayable = 1;
	}
	else
		_impossible = 1;
}

void	Conversion::cast(float f){
	std::stringstream ss;
	ss << f;
	std::string str = ss.str();
	int found = str.find('.');
	_precis = str.length() - found;
	_f = f;
	_d = static_cast<double>(f);
	if ((f <= std::numeric_limits<int>::max()) && ((f >= std::numeric_limits<int>::min())))
		_i = static_cast<int>(f);
	else
	{
		_overflow = 1;
		_impossible = 1;
		return ;
	}
	if (_i > 31 && _i < 127)
		_c = static_cast<char>(_i);
	else if ((_i >= 0 && _i <= 31) || (_i == 127))
		_nonDisplayable = 1;
	else
		_impossible = 1;
}

void    Conversion::cast(char c){
	_nonDisplayable = 0;
	_precis = 0;
	_c = c;
	_d = static_cast<double>(c);
	_i = static_cast<int>(_d);
	_f = static_cast<float>(_d);
}

void	Conversion::cast(int i){
	_precis = 0;
	_i = i;
	_d = static_cast<double>(_i);
	_f = static_cast<float>(_i);
	if (i > 31 && i < 127){
		_c = static_cast<char>(_i);
	}
	else if ((i >= 0 && i <= 31) || (i == 127)){
		_nonDisplayable = 1;
	}
	else
		_impossible = 1;
}

void    Conversion::print(void) {
	if (!_nonDisplayable && !_impossible){
		std::cout << "char is : "<< _c << std::endl;
	}
	else if (_nonDisplayable)
		std::cout << "char is : Non displayable" << std::endl;
	else if (_impossible)
		std::cout << "char is : impossible" << std::endl;
	if (isinf(_d) || isnan(_d))
		std::cout << "int is : impossible" << std::endl;
	else if (_overflow)
		std::cout << "int is : overflow" << std::endl;
	else
		std::cout << "int is : "<< _i << std::endl;
	if (!_precis || _f == 0)
	{
		_add = ".0";
		_precis = 3;
	}
	std::stringstream ss1;
	ss1 << _f << _add <<'f';
	std::cout << "float is : " << ss1.str() << std::endl;	
	std::cout << "double is : "<< std::setprecision(_precis) << _d << _add <<std::endl;
}

std::ostream & operator<<(std::ostream &output, Conversion & rhs)
{
	rhs.print();
	return (output);
}