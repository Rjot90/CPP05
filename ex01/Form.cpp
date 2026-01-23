#include "Form.hpp"

Form::Form() : _name("undefined"), _signed(false), _requiredGrade(0), _execGrade(0) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string Iname, const int IrG, const int eG) 
    : _name(Iname), _signed(false), _requiredGrade(IrG), _execGrade(eG) {
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

const char* Form::GradeTooHighException::what() const throw() {
    return ;
 }

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";