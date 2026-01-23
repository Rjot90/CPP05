#include "Bureaucrat.hpp"

int main(void) {

    try {
        Bureaucrat bob("Bob", 151);
        std::cout << "Grade is: " << bob.getGrade() << std::endl;
        std::cout << "Name is: " << bob.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat chris("chris", -12);
        std::cout << "Grade is: " << chris.getGrade() << std::endl;
        std::cout << "Name is: " << chris.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat saucisse("Saucisse", 150);
        saucisse.IncrementGrade();
        std::cout << "Grade is: " << saucisse.getGrade() << std::endl;
        std::cout << "Name is: " << saucisse.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        Bureaucrat steve("Steve", 14);
        std::cout << "Grade is: " << steve.getGrade() << std::endl;
        steve.IncrementGrade();
        std::cout << "Grade is: " << steve.getGrade() << std::endl;
        steve.DecrementGrade();
        std::cout << "Grade is: " << steve.getGrade() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    
    
    
}