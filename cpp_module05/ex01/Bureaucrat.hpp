/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:46:28 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/09 20:06:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H
# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const   std::string name;
    int                 grade;

protected:
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
    void        signForm(Form &form);

    class GradeTooHighException : public std::exception
    {
        private:
            const char *message;
        public:
            explicit GradeTooHighException(const char * message);
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        private:
            const char *message;
        public:
            explicit GradeTooLowException(const char *message);
            virtual const char *what() const throw();
    };
    class CanNotChangeConst : public std::exception
    {
        private:
            const char *message;
        public:
            explicit CanNotChangeConst(const char *message);
            virtual const char *what() const throw();
    };    
};

std::ostream & operator<<(std::ostream &output, Bureaucrat & rhs);

#endif