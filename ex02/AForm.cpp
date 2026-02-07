#include "AForm.hpp"

/*
-------------------------------
    CONSTRUCTORS

*/

AForm::AForm() : _name("undefined"), _signed(false), _requiredGrade(150), _execGrade(150) {
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(std::string Iname, const int IrG, const int eG) 
    : _name(Iname), _signed(false), _requiredGrade(IrG), _execGrade(eG) {
    if (IrG > 150)
        throw GradeTooLowException();
    else if (IrG < 1)
        throw GradeTooHighException();
    else if (eG > 150)
        throw ExecTooLowException();
    else if (eG < 1)
        throw ExecTooHighException();
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm assignment operator called" << std::endl;
    if (this != &other) {
        this->_signed = true;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called" << std::endl;
}

/*
-------------------------------
    GETTERS

*/

const std::string& AForm::getName() const {
    return _name;
}

int AForm::getGradeToExecute() const {
    return _execGrade;
}

int AForm::getGradeToSign() const {
    return _requiredGrade;
}

bool AForm::isSigned() const {
    return _signed;
}

/*
-------------------------------
    METHODS

*/

void    AForm::beSigned(const Bureaucrat& obj) {
    if (obj.getGrade() <= _requiredGrade)
        _signed = true;
    else
        throw GradeTooHighException();
}

void    AForm::execute(const Bureaucrat& executor) const {
    if (isSigned() == false)
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw ExecTooLowException();
}

/*
-------------------------------
    EXCEPTIONS

*/

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

const char* AForm::ExecTooHighException::what() const throw() {
    return "Exec Form grade is too high";
}

const char* AForm::ExecTooLowException::what() const throw() {
    return "Exec Form grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form isn't signed";
}

/*
-------------------------------
    OVERLOADS

*/

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form " << f.getName()
       << ", signed: " << f.isSigned()
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}

/*
               *       +
           '                  |
       ()    .-.,="``"=.    - o -
             '=/_       \     |
          *   |  '=._    |
               \     `=./`,        '
            .   '=.__.=' `='      *
   +                         +

*/