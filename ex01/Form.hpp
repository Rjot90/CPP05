#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form {
    private:
        std::string _name;
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

        //Methods
        void    beSigned(Bureaucrat obj);

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
