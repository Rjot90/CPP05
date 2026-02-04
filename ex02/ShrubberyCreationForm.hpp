#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    protected:
        void    action() const;
    public:
    //Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string ITarget);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
};
