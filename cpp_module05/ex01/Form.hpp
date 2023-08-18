/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <hyujung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:24:11 by hyunah            #+#    #+#             */
/*   Updated: 2023/02/09 20:06:05 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        std::string         signedBy;
        bool                isSigned;
        const int           requiredGrade;
        const int           requiredExec;
        
    public:
        Form();
        Form(std::string const name, int const requiredGrade, int const requiredExec);
        Form(const Form & rhs);
        ~Form();
        Form & operator=(const Form &rhs);

        std::string getName() const;
        std::string getSignedBy() const;
        void        setSignedBy(std::string const name);
        bool        getIsSigned() const;
        void        setIsSigned(bool const b);
        int         getRequiredGrade() const;
        int         getRequiredExec() const;
        void        beSigned(Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
        private:
            const char  *message;
        public:
            explicit GradeTooHighException(const char *message);
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        private:
            const char  *message;
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

std::ostream & operator<<(std::ostream &output, const Form &rhs);
#endif