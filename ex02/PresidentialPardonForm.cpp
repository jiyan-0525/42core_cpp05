#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("PresidentialPardonForm", 25, 5), _target("") {} // the OCF rule use "" as a placeholder for the target

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) 
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    AForm::operator=(other);
    if (this != &other) {
        _target = other._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
