#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <fstream>

int main() {
    try {
        std::cout << "--- Test 1: ShrubberyCreationForm ---" << std::endl;
        Bureaucrat john("John", 100);
        ShrubberyCreationForm shrubbery("home");
       
        john.signForm(shrubbery);
        john.executeForm(shrubbery);

        if (std::ifstream("home_shrubbery").good()) {
                std::cout << "✓ File 'home_shrubbery' created." << std::endl;
            } else {
                std::cerr << "✗ File 'home_shrubbery' was not created." << std::endl;
            }
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Test 2: RobotomyRequestForm ---" << std::endl;
        Bureaucrat jane("Jane", 40);
        RobotomyRequestForm robotomy("Alice");
        
        std::cout << jane << std::endl;
        std::cout << robotomy << std::endl;
        
        jane.signForm(robotomy);
        jane.executeForm(robotomy);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Test 3: PresidentialPardonForm ---" << std::endl;
        Bureaucrat president("President", 3);
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Test 4: Execute unsigned form (should fail) ---" << std::endl;
        Bureaucrat bob("Bob", 1);
        ShrubberyCreationForm unsigned_form("garden");
        
        std::cout << bob << std::endl;
        bob.executeForm(unsigned_form);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Test 5: Grade too low to sign (should fail) ---" << std::endl;
        Bureaucrat low_grade("LowGrade", 150);
        ShrubberyCreationForm form("park");
        
        std::cout << low_grade << std::endl;
        std::cout << form << std::endl;
        
        low_grade.signForm(form);
        low_grade.executeForm(form);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n--- Test 6: Grade too low to execute (should fail) ---" << std::endl;
        Bureaucrat mediocre("Mediocre", 140);
        RobotomyRequestForm robotomy2("Target");
        
        std::cout << mediocre << std::endl;
        std::cout << robotomy2 << std::endl;
        
        mediocre.signForm(robotomy2);
        mediocre.executeForm(robotomy2);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}