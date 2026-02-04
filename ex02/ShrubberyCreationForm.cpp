#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DefaultShrubberyForm", 145, 137), _target("Default_target") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string ITarget) : AForm(ITarget, 145, 137), _target(ITarget) {
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void    ShrubberyCreationForm::action() const {
    std::ofstream outfile((_target + "_shrubbery").c_str());
    
    outfile << R"(
                     .o00o
                   o000000oo
                  00000000000o
                 00000000000000
              oooooo  00000000  o88o
           ooOOOOOOOoo  ```''  888888
         OOOOOOOOOOOO'.qQQQQq. `8888'
        oOOOOOOOOOO'.QQQQQQQQQQ/.88'
        OOOOOOOOOO'.QQQQQQQQQQ/ /q
         OOOOOOOOO QQQQQQQQQQ/ /QQ
           OOOOOOOOO `QQQQQQ/ /QQ'
             OO:F_P:O `QQQ/  /Q'
                \\. \ |  // |
                d\ \\\|_////
                qP| \\ _' `|Ob
                   \  / \  \Op
                   |  | O| |
           _       /\. \_/ /\
            `---__/|_\\   //|  __
                  `-'  `-'`-'-' )";
    std::cout << "Shrubbery file successfully created as " << _target << "_shruberry" << std::endl;
}

