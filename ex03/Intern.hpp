#pragma once

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {
    public:
        Intern();
        ~Intern();

    // Methods
    AForm& makeForm(std::string NameForm, std::string NameTarget);
};
