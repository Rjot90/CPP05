#include "Form.hpp"
// CONSTRUCTORS

Form::Form() : _name("undefined"), _signed(false), _requiredGrade(0), _execGrade(0) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string Iname, const int IrG, const int eG) 
    : _name(Iname), _signed(false), _requiredGrade(IrG), _execGrade(eG) {
    if (IrG > 150)
        throw GradeTooLowException();
    else if (IrG < 1)
        throw GradeTooHighException();
    else if (eG > 150)
        throw ExecTooLowException();
    else if (eG < 1)
        throw ExecTooHighException();
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), _requiredGrade(other._requiredGrade), _execGrade(other._execGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form assignment operator called" << std::endl;
    if (this != &other) {
        this->_signed = true;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

/*
-------------------------------
    GETTERS

*/

const std::string& Form::getName() const {
    return _name;
}

int Form::getGradeToExecute() const {
    return _execGrade;
}

int Form::getGradeToSign() const {
    return _requiredGrade;
}

bool Form::isSigned() const {
    return _signed;
}

/*
-------------------------------
    METHODS

*/

void    Form::beSigned(const Bureaucrat& obj) {
    if (obj.getGrade() <= _requiredGrade)
        _signed = true;
    else
        throw GradeTooHighException();
}

/*
-------------------------------
    EXCEPTIONS

*/

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

const char* Form::ExecTooHighException::what() const throw() {
    return "Exec form grade is too high";
}

const char* Form::ExecTooLowException::what() const throw() {
    return "Exec form grade is too low";
}

/*
-------------------------------
    OVERLOADS

*/

std::ostream& operator<<(std::ostream& os, const Form& f) {
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