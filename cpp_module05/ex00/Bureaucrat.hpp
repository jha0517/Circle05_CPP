/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunahjung <hyunahjung@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:46:28 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/10 13:46:50 by hyunahjung       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>
# include <string>
# include <stdexcept>
# include "printColor.hpp"

class Bureaucrat
{
private:
    const   std::string name;
    int                 grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const n, int const g);
    Bureaucrat(const Bureaucrat &rhs);
    ~Bureaucrat();
    Bureaucrat & operator=(const Bureaucrat &rhs);

    std::string getName() const;
    int         getGrade() const;
    void        degrade();
    void        promote();

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw()
            {
                return ("ERROR : Grade too high.");
            }
    };
    class GradeTooLowException : public std::exception
    {
        public :
            virtual const char *what() const throw()
            {
                return ("ERROR : Grade too low.");
            }
    };
    class CanNotChangeConst : public std::exception
    {
        public :
            virtual const char *what() const throw()
            {
                return ("Error : Can not change CONST name. Only Grade has been copied.");
            }
    };    
};

std::ostream & operator<<(std::ostream &output, Bureaucrat & rhs);

#endif