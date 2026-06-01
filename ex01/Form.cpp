#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>
#include <string_view>

Form::Form() 
    : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

Form::Form(std::string_view name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &copy)
    : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) {}

Form & Form::operator=(Form const &copy)
{
    if (this != &copy)
        this->_isSigned = copy._isSigned;
    return *this;
}

Form::~Form(){}

std::string_view Form::getName() const
{
    return this->_name;
}

bool Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getGradeToSign() const
{
    return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form: " << form.getName() 
        << ", [Signed: " << std::boolalpha << form.getIsSigned() << "]"
        << ", Grade to Sign: " << form.getGradeToSign() 
        << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}
