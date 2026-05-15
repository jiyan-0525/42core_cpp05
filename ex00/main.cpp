#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b1("Alice", 151);
        std::cout << b1 << std::endl;
        b1.incrementGrade();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
