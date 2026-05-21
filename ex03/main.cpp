#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== 1. Intern Creation Test ===" << std::endl;
    Intern someRandomIntern;
    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    AForm* unknown = NULL;

    std::cout << "\n--- Test Case 1: Success - Robotomy Request ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        std::cout << "Form Name: " << rrf->getName() << std::endl;
        try {
            Bureaucrat boss("The Boss", 1);
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
        } catch (std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        delete rrf;
    }

    std::cout << "\n--- Test Case 2: Success - Shrubbery Creation ---" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (scf) {
        delete scf;
    }

    std::cout << "\n--- Test Case 3: Success - Presidential Pardon ---" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (ppf) {
        delete ppf;
    }

    std::cout << "\n--- Test Case 4: Failure - Unknown Form ---" << std::endl;
    unknown = someRandomIntern.makeForm("coffee request", "Intern Self");
    if (unknown == NULL) {
        std::cout << "Great, Intern safely returned NULL for invalid form name." << std::endl;
    } else {
        std::cout << "Oops, something went wrong, unknown form should be NULL!" << std::endl;
        delete unknown;
    }

    std::cout << "\n==========================================" << std::endl;
    return 0;
}