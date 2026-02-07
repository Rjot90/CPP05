#pragma once
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>

class Intern {
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

    // Methods
    AForm* makeForm(std::string NameForm, std::string NameTarget);
    AForm* makeShrubbery(const std::string target);
    AForm* makeRobotomy(const std::string target);
    AForm* makePresidential(const std::string target);
};
