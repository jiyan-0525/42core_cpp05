#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 149);
    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    try {
        bob.incrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Error incrementing Bob's grade: " << e.what() << std::endl;
    }
    try {
        alice.decrementGrade();
    } catch (const std::exception& e) {
        std::cerr << "Error decrementing Alice's grade: " << e.what() << std::endl;
    }

    return 0;
}
