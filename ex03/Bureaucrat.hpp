#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
    private:
        std::string _name;
        int         _grade;

    public:
        //Constructors
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
        void    signForm(AForm& f);
        void    executeForm(AForm const & form) const;

        //Exception
		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

//Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
