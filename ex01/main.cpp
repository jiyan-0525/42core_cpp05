#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "-----Test 1: Successful -----" << std::endl;
    try {
        Bureaucrat john("John", 150);
        Form taxForm("Tax-Form", 50, 40);
        std::cout << john << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);
        std::cout << taxForm << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n-----Test 2: Failed -----" << std::endl;
    try {
        Bureaucrat low("LowRank", 100);
        Form restrictedForm("RestrictedForm", 50, 40);
        std::cout << low << std::endl;
        std::cout << restrictedForm << std::endl;

        low.signForm(restrictedForm);
        std::cout << restrictedForm << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}