#include "Form.hpp"

Form::Form() : _name("undefined"), _signed(false), _requiredGrade(0), _execGrade(0) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string Iname, const int IrG, const int eG) 
    : _name(Iname), _signed(false), _requiredGrade(IrG), _execGrade(eG) {
    if (IrG > 150)
        throw GradeTooHighException();
    else if (IrG < 1)
        throw GradeTooLowException();
    else if (eG > 150)
        throw ExecTooHighException();
    else if (eG < 1)
        throw ExecTooLowException();
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

void    Form::beSigned(Bureaucrat obj) {
    if (obj.getGrade() <= _requiredGrade) {
        _signed = true;
        std::cout << obj.getName() << "signed" << _name << std::endl;        
    }
    else
        std::cout << obj.getName() << "couldn't sign" << _name << "because";
    throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* Form::ExecTooHighException::what() const throw() {
    return "Exec grade is too high";
}

const char* Form::ExecTooLowException::what() const throw() {
    return "Exec grade is too low";
}