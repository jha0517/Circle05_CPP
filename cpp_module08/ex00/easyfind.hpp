/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:07:06 by hyujung           #+#    #+#             */
/*   Updated: 2023/02/10 19:04:58 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_H
# define EASYFIND_H
# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
typename T::const_iterator easyfind(T const & t, int const & i)
{
	return (std::find(t.begin(), t.end(), i));
}

template <typename T>
typename T::iterator easyfind(T & t, int const & i)
{
	return (std::find(t.begin(), t.end(), i));
}
#endif