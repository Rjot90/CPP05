#include "Bureaucrat.hpp"

/*
-------------------------------
    CONSTRUCTORS

*/

Bureaucrat::Bureaucrat() : _name("undefined"), _grade(0) {
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string InputName, int InputGrade) {
    if (InputGrade > 150)
        throw GradeTooHighException();
    else if (InputGrade < 1)
        throw GradeTooLowException();
    else {
        this->_grade = InputGrade;
        this->_name = InputName;
    }
    std::cout << "---" << std::endl << "Bureaucrat constructor called" << std::endl;
    std::cout << "Bureaucrat name's: " << _name << std::endl << 
                "Bureacrat grade's: " << _grade << std::endl << "---" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &other) {
        this->_grade = other._grade;
        this->_name = other._name;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called" << std::endl;
}

/*
-------------------------------
    GETTERS

*/

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

/*
-------------------------------
    METHODS

*/

void    Bureaucrat::IncrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooHighException();
    _grade++;
    std::cout << "Grade is now : " << _grade << std::endl;
}

void    Bureaucrat::DecrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooLowException();
    _grade--;
    std::cout << "Grade is now: " << _grade << std::endl;
}

void    Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << _name << " couldn’t sign "
                  << f.getName()
                  << " because " << e.what()
                  << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form) const {
    form.execute(*this);
}

/*
-------------------------------
    EXCEPTIONS

*/

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

/*
-------------------------------
    OVERLOADS

*/

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << "Name: " << b.getName() << std::endl << "Grade: " << b.getGrade() << std::endl;
    return os; 
}
