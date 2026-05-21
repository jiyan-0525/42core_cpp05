#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    AForm::operator=(other);
    if (this != &other) {
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()) {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > getGradeToExecute()) {
        throw AForm::GradeTooLowException();
    }
    
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    
    file << "    ^\n";
    file << "   ^^^\n";
    file << "  ^^^^^\n";
    file << " ^^^^^^^\n";
    file << "^^^^^^^^^\n";
    file << "   |||\n";
    file << "   |||\n";
    file << "\n";
    file << "    ^\n";
    file << "   ^^^\n";
    file << "  ^^^^^\n";
    file << " ^^^^^^^\n";
    file << "^^^^^^^^^\n";
    file << "   |||\n";
    file << "   |||\n";
    
    file.close();
}
