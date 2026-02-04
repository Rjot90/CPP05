#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class AForm {
    private:
        const std::string _name;
        bool        _signed;
        const int   _requiredGrade;
        const int   _execGrade;
    protected:
        virtual void action() = 0;
    public:
        //Constructors
        AForm();
        AForm(std::string Iname, const int IrG, const int eG);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        //Getters
        const std::string& getName() const;
        bool               isSigned() const;
        int                getGradeToSign() const;
        int                getGradeToExecute() const;

        //Methods
        void    beSigned(const Bureaucrat& obj);
        void    execute(const Bureaucrat& executor);

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

        class FormNotSignedException : public std::exception {
			const char* what() const throw();
		};
};

//Overload
std::ostream& operator<<(std::ostream& os, const AForm& f);
