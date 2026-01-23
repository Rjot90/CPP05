#pragma once

#include <iostream>
#include <string>

class Form {
    private:
        std::string _name;
        bool        _signed;
        const int   _requiredGrade;
        const int   _execGrade;
    public:
        Form();
        Form(std::string Iname, const int IrG, const int eG);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        class GradeTooHighException : public std::exception {
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			const char* what() const throw();
		};
};
