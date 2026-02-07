#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    std::srand(std::time(NULL));

    try {
        std::cout << "===== CREATION DES BUREAUCRATS =====" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat mid("Mid", 70);
        Bureaucrat noob("Noob", 150);

        std::cout << boss << std::endl;
        std::cout << mid << std::endl;
        std::cout << noob << std::endl;

        std::cout << std::endl << "===== CREATION DES FORMS =====" << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm   robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl;

        std::cout << std::endl << "===== TEST 1 : EXECUTION SANS SIGNATURE =====" << std::endl;
        try {
            boss.executeForm(shrub);
        }
        catch (const std::exception& e) {
            std::cout << "Caught in main: " << e.what() << std::endl;
        }

        std::cout << std::endl << "===== TEST 2 : SHRUBBERY OK =====" << std::endl;
        boss.signForm(shrub);
        boss.executeForm(shrub);

        std::cout << std::endl << "===== TEST 3 : ROBOTOMY (50%) =====" << std::endl;
        boss.signForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);

        std::cout << std::endl << "===== TEST 4 : PRESIDENTIAL PARDON =====" << std::endl;
        boss.signForm(pardon);
        boss.executeForm(pardon);

        std::cout << std::endl << "===== TEST 5 : GRADE TROP FAIBLE =====" << std::endl;
        try {
            mid.signForm(robot);     // OK
            mid.executeForm(robot);  // FAIL
        }
        catch (const std::exception& e) {
            std::cout << "Caught in main: " << e.what() << std::endl;
        }

        std::cout << std::endl << "===== TEST 6 : NOOB (TOUT FAIL) =====" << std::endl;
        try {
            noob.signForm(pardon);
            noob.executeForm(pardon);
        }
        catch (const std::exception& e) {
            std::cout << "Caught in main: " << e.what() << std::endl;
        }

        std::cout << std::endl << "===== FIN DES TESTS =====" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "FATAL ERROR: " << e.what() << std::endl;
    }

    return 0;
}
