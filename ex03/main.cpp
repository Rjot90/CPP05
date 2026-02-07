#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
    std::srand(std::time(NULL));

    try {
        std::cout << "===== CREATION DU BUREAUCRAT =====" << std::endl;
        Bureaucrat boss("Boss", 1);
        std::cout << boss << std::endl;

        std::cout << "\n===== CREATION DE L'INTERN =====" << std::endl;
        Intern someRandomIntern;

        std::cout << "\n===== TEST 1 : CREATION DE FORMS VALIDES =====" << std::endl;
        try {
            AForm* f1 = someRandomIntern.makeForm("shrubbery creation", "home");
            AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
            AForm* f3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

            boss.signForm(*f1);
            boss.executeForm(*f1);

            boss.signForm(*f2);
            boss.executeForm(*f2);

            boss.signForm(*f3);
            boss.executeForm(*f3);

            delete f1;
            delete f2;
            delete f3;
        }
        catch (const std::exception& e) {
            std::cout << "Caught in TEST 1: " << e.what() << std::endl;
        }

        std::cout << "\n===== TEST 2 : FORM INCONNUE (DOIT FAIL) =====" << std::endl;
        try {
            AForm* bad = someRandomIntern.makeForm("tax evasion", "Bercy");
            delete bad;
        }
        catch (const std::exception& e) {
            std::cout << "Caught in TEST 2: " << e.what() << std::endl;
        }

        std::cout << "\n===== TEST 3 : EXECUTION AVEC GRADE TROP FAIBLE =====" << std::endl;
        try {
            Bureaucrat noob("Noob", 150);
            AForm* f = someRandomIntern.makeForm("robotomy request", "Marvin");

            noob.signForm(*f);      // doit FAIL ou passer selon ton implémentation
            noob.executeForm(*f);   // doit FAIL

            delete f;
        }
        catch (const std::exception& e) {
            std::cout << "Caught in TEST 3: " << e.what() << std::endl;
        }

        std::cout << "\n===== FIN DES TESTS ex03 =====" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "FATAL ERROR: " << e.what() << std::endl;
    }

    return 0;
}
