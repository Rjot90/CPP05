#pragma once
#include "Form.hpp"
#include <iostream>
#include <string>

class Bureaucrat {
    private:
        std::string _name;
        int         _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string InputName,int InputGrade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        //Getters
        std::string getName() const;
        int         getGrade() const;

        //Methods
        void    IncrementGrade();
        void    DecrementGrade();
        void    signForm(Form& f);

        //Exception
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};
