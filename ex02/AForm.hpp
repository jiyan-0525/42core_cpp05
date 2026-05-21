#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <exception>
# include <string>

class Bureaucrat;

class AForm {
public:
    AForm();
    AForm(std::string const &name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other); 
    virtual ~AForm();
    
    std::string const &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat const &bureaucrat);
    
    virtual void execute(Bureaucrat const &executor) const = 0;

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

    class FormNotSignedException : public std::exception {
    public:
        const char *what() const noexcept override {
            return "Form is not signed";
        }
    };

private:
    std::string _name;
    bool _isSigned;
    int const _gradeToSign;
    int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif