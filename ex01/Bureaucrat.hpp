#pragma once
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

        std::string getName();
        int         getGrade();

        void    IncrementGrade();
        void    DecrementGrade();

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};
