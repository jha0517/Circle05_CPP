/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:24:50 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 19:58:56 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H
# include <iostream>
# include <string>
# include <sstream>
# include <stdlib.h>
# include <iomanip>
# include <cmath>
# include <limits>

#define T_FLOAT 1
#define T_INT 2
#define T_CHAR 3
#define T_DOUBLE 4
#define T_SPECIAL 5

class Conversion
{
protected:
	double	_d;
	float	_f;
	int     _i;
	char    _c;
	int		_precis;
    int     _impossible;
    int     _nonDisplayable;
    int     _overflow;
	std::string	_add;

public:
    Conversion();
    Conversion(const Conversion &rhs);
    ~Conversion();
    Conversion & operator=(const Conversion &rhs);
    
    void    cast(double d);
    void    cast(float f);
    void    cast(int d);
    void    cast(char c);
    void    print(void);
};

std::ostream & operator<<(std::ostream &output, Conversion & rhs);

#endif