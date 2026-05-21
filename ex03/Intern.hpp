#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"
#include <string>
#include <string_view>
#include <exception>
#include <iostream>

class Intern {
public:
    Intern();
    Intern(std::string_view name);
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm *makeForm(std::string const &formName, std::string const &target) const;

private:
    AForm *createShrubberyCreationForm(std::string const &target) const;
    AForm *createRobotomyRequestForm(std::string const &target) const;
    AForm *createPresidentialPardonForm(std::string const &target) const;
};

#endif