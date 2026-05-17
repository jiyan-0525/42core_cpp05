#ifndef FORM_HPP
# define FORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {
public:
    Form();
    Form(std::string_view name, int gradeToSign, int gradeToExecute);
    Form(Form const &other);
    Form &operator=(Form const &other); 
    ~Form();
    
    std::string_view getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const &bureaucrat);
    
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
    std::string_view const	_name;
    bool				_isSigned;
    int const			_gradeToSign;
    int const			_gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif