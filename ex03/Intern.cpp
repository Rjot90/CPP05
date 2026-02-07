#include "Intern.hpp"
/*
-------------------------------
    CONSTRUCTORS

*/

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern assignement constructor called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

/*
-------------------------------
    METHODS

*/

AForm*  Intern::makeForm(std::string NameForm, std::string NameTarget) {
    std::string s[3] = {
        "robotomy request", "shrubbery creation", "presidential pardon"
    };
    AForm* (Intern::*fp[3])(const std::string target) = {
        &Intern::makeRobotomy,
        &Intern::makeShrubbery,
        &Intern::makePresidential
    };
    for (int i = 0; i < 3; i++) {
        if (NameForm == s[i]) {
            std::cout << "Intern creates " << NameForm << std::endl;
            return ((this->*fp[i])(NameTarget));
        }
    }
    std::cout << "Intern can't creates " << NameForm << std::endl;
    return NULL;
}

AForm* Intern::makeShrubbery(const std::string target) {
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomy(const std::string target) {
    return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidential(const std::string target) {
    return (new PresidentialPardonForm(target));
}
