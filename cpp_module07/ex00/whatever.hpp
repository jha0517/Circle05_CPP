/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:44:57 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/11 11:28:56 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template< typename T >
T	max( T const & x, T const & y)
{
	return ( (x > y) ? x : y);
}

template< typename T >
T	min( T const & x, T const & y)
{
	return ( (x < y) ? x : y);
}

template< typename T >
void	swap( T & x, T & y)
{
	T	tmp;
	tmp = y;
	y = x;
	x = tmp;
	return ;
}

#endif
