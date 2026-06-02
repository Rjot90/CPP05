#pragma once
#include <iostream>
#include <string>

class Bureaucrat {
    private:
    const std::string _name;
    int         _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string InputName,int InputGrade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        int         getGrade() const;

        void    IncrementGrade();
        void    DecrementGrade();

		class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};

//Overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
