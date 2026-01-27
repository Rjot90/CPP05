#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
    public:
    //Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

    // Methods
        void beSigned(const Bureaucrat& obj);
};
