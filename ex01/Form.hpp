#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool        _signed;
        const int   _requiredGrade;
        const int   _execGrade;
    public:
        //Constructor
        Form();
        Form(std::string Iname, const int IrG, const int eG);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        //Getters
        const std::string& getName() const;
        bool               isSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;

        //Methods
        void    beSigned(const Bureaucrat& obj);

        //Exception
        class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();

		};

        class ExecTooHighException : public std::exception {
			const char* what() const throw();
		};

		class ExecTooLowException : public std::exception {
			const char* what() const throw();
		};
};

//overload
std::ostream& operator<<(std::ostream& os, const Form& f);
