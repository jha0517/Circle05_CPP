/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 09:01:56 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/10 11:26:59 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H
# include <iostream>
# include <string>
# include <stdint.h>
# include <sstream>

struct Data{
	int	i;
};

uintptr_t serialize(Data* ptr){return (reinterpret_cast<uintptr_t>(ptr));}

Data * deserialize(uintptr_t raw){return (reinterpret_cast<Data *>(raw));}

#endif
