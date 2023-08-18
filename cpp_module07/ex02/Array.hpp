/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:44:57 by hyunahjung        #+#    #+#             */
/*   Updated: 2023/02/11 20:30:22 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <iostream>
# include <stdexcept>
# include "printColor.hpp"
# include <string>

template <typename T>
class Array {
    public :
        Array<T>(void) :_size(0), _array(0) {
            std::cout << "Default constructor Called" << std::endl;
        };
        Array<T>(Array<T> const & src) : _size(src._size) {
            std::cout << "Copy constructor Called" << std::endl;
            if (src._size != 0)
            {
                this->_size = src._size;
                this->_array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                {
                    this->_array[i] = src._array[i];
                }
            }
        };
        Array<T>(unsigned int const n) : _size(n) {
            std::cout << "Param constructor Called" << std::endl;
            if (n >= 0)
                this->_array = new T[n];
            else
                throw Array::overflowError();
        };

        ~Array<T>(void){
            std::cout << "Destructor Called" << std::endl;
            if (_array != 0)
                delete [] this->_array;
        };

        unsigned int    size() const{
            return (_size);
        }
        Array & operator=(Array<T> const & rhs){
            // std::cout << "Assignement= Operator Called" << std::endl;
            if (_array != NULL)
                delete [] this->_array;
            if (rhs._size != 0)
            {
                this->_size = rhs._size;
                this->_array = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                {
                    this->_array[i] = rhs._array[i];
                }
            }
            return (*this);
        }

        T & operator[](unsigned int content) const
        {
            // std::cout << "Assignement[] Operator Called" << std::endl;
            if (_size <= content || content < 0)
            {
                throw Array::overflowError();
            }
            return (_array[content]);
        }

        class overflowError : public std::exception
        {
            public :
                virtual const char *what() const throw()
                {return ("ERROR : overflow, index out of bounds");}
        };
    
    private :
        unsigned int    _size;
        T *             _array;
};

#endif