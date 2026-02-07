#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("DefaultRobotomy", 72, 45), _target("Default target") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string ITarget) : AForm(ITarget, 72, 45), _target(ITarget) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void    RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (isSigned() == false)
        throw FormNotSignedException();
    else if (executor.getGrade() > getGradeToExecute())
        throw ExecTooLowException();

    //Action
    bool res = (rand() % 2) == 1;
    if (res)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << "The robotomy failed" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& pf) {
    os << "RobotomyRequestForm Target's: " << pf.getName() << std::endl
        << "Is signed: " << pf.isSigned() << std::endl << "Grade to sign: " <<
        pf.getGradeToSign() << std::endl << "Grade to exec: " << pf.getGradeToExecute();
    return os;
}