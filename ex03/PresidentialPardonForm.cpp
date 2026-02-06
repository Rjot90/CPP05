#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("DefaultPresidential", 25, 5), _target("Default target") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string ITarget) : AForm(ITarget, 25, 5), _target(ITarget) {
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

void PresidentialPardonForm::action() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& pf) {
    os << "PresidentialPardonForm Target's: " << pf.getName() << std::endl
        << "Is signed: " << pf.isSigned() << std::endl << "Grade to sign: " <<
        pf.getGradeToSign() << std::endl << "Grade to exec: " << pf.getGradeToExecute();
    return os;
}

