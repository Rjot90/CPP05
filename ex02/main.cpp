#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main() {
    try {
        Bureaucrat valid("Valid", 29);
        Form form1("ValidForm", 30, 10);
        Bureaucrat bob("Bob", 50);
        Form form2("TopSecret", 30, 10);

        std::cout << form1 << std::endl;
        valid.signForm(form1);
        std::cout << form1 << std::endl;
        std::cout << "----" << std::endl;
        std::cout << form2 << std::endl;
        bob.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}