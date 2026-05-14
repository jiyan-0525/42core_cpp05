#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(std::string_view name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Grade is too high (must be >= 1)";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Grade is too low (must be <= 150)";
        }
    };

private:
    std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
