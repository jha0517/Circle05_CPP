/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunah <hyunah@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:24:11 by hyunah            #+#    #+#             */
/*   Updated: 2023/01/14 20:54:45 by hyunah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_H
# define AForm_H
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
# include "printColor.hpp"
# include <fstream>

class Bureaucrat;

class AForm
{
private:
    std::string name;
    bool        isSigned;
    const int   requiredGrade;
    const int   requiredExec;
    std::string target;
    std::string signedBy;
    
public:
    AForm();
    AForm(std::string const name, int const requiredGrade, int const requiredExec, std::string const target);
    AForm(const AForm &rhs);
    virtual ~AForm();
    AForm & operator=(const AForm &rhs);

    std::string     getName() const;
    std::string     getSignedBy() const;
    void            setSignedBy(std::string const name);
    std::string     getTarget() const;
    void            setTarget(std::string const target);
    bool            getIsSigned() const;
    void            setIsSigned(bool const b);
    int             getRequiredGrade() const;
    int             getRequiredExec() const;
    int             checkExecutable(Bureaucrat const & executor) const;
    void            beSigned(Bureaucrat &b);
    virtual void    execute(Bureaucrat const & executor) const = 0;

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
};

std::ostream & operator<<(std::ostream &output, const AForm &rhs);

#endif