#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name(""), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw AForm::GradeTooHighException();
    }
    if (gradeToSign > 150 || gradeToExecute > 150) {
        throw AForm::GradeTooLowException();
    }
}

AForm::AForm(AForm const &other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm &AForm::operator=(AForm const &other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

AForm::~AForm() {}

std::string const &AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form: " << form.getName() 
        << ", [Signed: " << std::boolalpha << form.getIsSigned() << "]"
        << ", Grade to Sign: " << form.getGradeToSign() 
        << ", Grade to Execute: " << form.getGradeToExecute();
    return out;
}