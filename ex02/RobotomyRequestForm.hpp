#pragma once

#include <AForm.hpp>
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    protected:
        void action() const;
    public:
        //Constructor
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string ITarget);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();
};
