#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(std::string_view name) {
    (void)name;
}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &formName, std::string const &target) const {
   std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

AForm* (Intern::*formCreators[3])(std::string const &target) const = {
    &Intern::createShrubberyCreationForm,
    &Intern::createRobotomyRequestForm,
    &Intern::createPresidentialPardonForm
};

for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i]) {
        std::cout << "Intern creates form: " << formName << std::endl;
        return (this->*formCreators[i])(target);
    }
}
std::cout << "Intern cannot create form: " << formName << " because it does not exist." << std::endl;
        return nullptr;
}

AForm *Intern::createShrubberyCreationForm(std::string const &target) const {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target) const {
    return new PresidentialPardonForm(target);
}
