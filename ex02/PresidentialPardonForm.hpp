#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    protected:
        void action() const;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string ITarget);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();
};
