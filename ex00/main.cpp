#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Creating valid Bureaucrats ===" << std::endl;
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 75);
        std::cout << b3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade too high (< 1) ===" << std::endl;
    try {
        Bureaucrat b4("Dave", 0);
        std::cout << b4 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade too low (> 150) ===" << std::endl;
    try {
        Bureaucrat b5("Eve", 151);
        std::cout << b5 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Incrementing grade ===" << std::endl;
    try {
        Bureaucrat b6("Frank", 5);
        std::cout << "Before increment: " << b6 << std::endl;
        b6.incrementGrade();
        std::cout << "After increment: " << b6 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Increment at highest grade (should fail) ===" << std::endl;
    try {
        Bureaucrat b7("Grace", 1);
        std::cout << "Before increment: " << b7 << std::endl;
        b7.incrementGrade();
        std::cout << "After increment: " << b7 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Decrementing grade ===" << std::endl;
    try {
        Bureaucrat b8("Henry", 145);
        std::cout << "Before decrement: " << b8 << std::endl;
        b8.decrementGrade();
        std::cout << "After decrement: " << b8 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: Decrement at lowest grade (should fail) ===" << std::endl;
    try {
        Bureaucrat b9("Iris", 150);
        std::cout << "Before decrement: " << b9 << std::endl;
        b9.decrementGrade();
        std::cout << "After decrement: " << b9 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Copy constructor and assignment ===" << std::endl;
    try {
        Bureaucrat b10("Jack", 50);
        Bureaucrat b11(b10);
        std::cout << "Original: " << b10 << std::endl;
        std::cout << "Copy: " << b11 << std::endl;
        
        Bureaucrat b12("Jill", 100);
        b12 = b10;
        std::cout << "After assignment: " << b12 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
