#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

int main() {
    srand(time(0));
    Intern someRandomIntern;
    AForm* rrf = NULL;
    AForm* scf = NULL;
    AForm* ppf = NULL;
    AForm* unknown = NULL;

    std::cout << "\n--- Test Case 1: Success - Robotomy Request ---" << std::endl;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    if (rrf) {
        try {
            Bureaucrat boss("The Boss", 1);
            boss.signForm(*rrf);
            for (int i = 0; i < 4; i++) {
                boss.executeForm(*rrf);
            }
        } catch (std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        delete rrf;
    }

    std::cout << "\n--- Test Case 2: Success - Shrubbery Creation ---" << std::endl;
    scf = someRandomIntern.makeForm("shrubbery creation", "home");
    if (scf) {
       try {
            Bureaucrat gardener("Gardener", 150);
            gardener.signForm(*scf);
            gardener.executeForm(*scf);
            if (std::ifstream("home_shrubbery").good()) {
                std::cout << "✓ File 'home_shrubbery' created." << std::endl;
            } else {
                std::cerr << "✗ File 'home_shrubbery' was not created." << std::endl;
            }
        } catch (std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
        delete scf;
    }

    std::cout << "\n--- Test Case 3: Success - Presidential Pardon ---" << std::endl;
    ppf = someRandomIntern.makeForm("presidential pardon", "Marvin");
    if (ppf) {
        try {
            Bureaucrat president("The President", 1);
            president.signForm(*ppf);
            president.executeForm(*ppf);
        } catch (std::exception& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
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

    return 0;
}