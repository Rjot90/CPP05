#include "ShrubberyCreationForm.hpp"

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

void    ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (isSigned() == false)
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw ExecTooLowException();

    std::ofstream outfile((_target + "_shrubbery").c_str());
    
    outfile <<
    "                     .o00o\n"
    "                   o000000oo\n"
    "                  00000000000o\n"
    "                 00000000000000\n"
    "              oooooo  00000000  o88o\n"
    "           ooOOOOOOOoo  ```''  888888\n"
    "         OOOOOOOOOOOO'.qQQQQq. `8888'\n"
    "        oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
    "        OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
    "         OOOOOOOOO QQQQQQQQQQ/ /QQ\n"
    "           OOOOOOOOO `QQQQQQ/ /QQ'\n"
    "             OO:F_P:O `QQQ/  /Q'\n"
    "                \\\\. \\\\ |  // |\n"
    "                d\\ \\|||_////\n"
    "                qP| \\ _' `|Ob\n"
    "                   \\  / \\  \\Op\n"
    "                   |  | O| |\n"
    "           _       /\\. \\_/ /\\\n"
    "            `---__/|_\\\\   //|  __\n"
    "                  `-'  `-'`-'-'\n";
    std::cout << "Shrubbery file successfully created as " << _target << "_shruberry" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& pf) {
    os << "ShrubberyCreationForm Target's: " << pf.getName() << std::endl
        << "Is signed: " << pf.isSigned() << std::endl << "Grade to sign: " <<
        pf.getGradeToSign() << std::endl << "Grade to exec: " << pf.getGradeToExecute();
    return os;
}