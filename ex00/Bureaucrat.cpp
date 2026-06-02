#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("undefined"), _grade(0) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string InputName, int InputGrade) : _name(InputName), _grade(InputGrade) {
    if (InputGrade > 150)
        throw GradeTooHighException();
    else if (InputGrade < 1)
        throw GradeTooLowException();
    std::cout << "---" << std::endl << "Bureaucrat constructor called" << std::endl;
    std::cout << "Bureaucrat name's: " << _name << std::endl << 
                "Bureacrat grade's: " << _grade << std::endl << "---" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    this->_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
    return this->_name;
}

int Bureaucrat::getGrade() const {
    return this->_grade;
}

void    Bureaucrat::IncrementGrade() {
    if (this->_grade - 1 < 1)
        throw GradeTooHighException();
    this->_grade--;
    std::cout << "Grade is now : " << this->_grade << std::endl;
}

void    Bureaucrat::DecrementGrade() {
    if (this->_grade + 1 > 150)
        throw GradeTooLowException();
    this->_grade++;
    std::cout << "Grade is now: " << this->_grade << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
 }

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
 }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << "Name: " << b.getName() << std::endl << "Grade: " << b.getGrade() << std::endl;
    return os;
}
