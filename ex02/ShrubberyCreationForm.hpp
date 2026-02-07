#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm {
    private:
        std::string _target;
    public:
    //Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string ITarget);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        //Methods
        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& pf);
