#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const int _gradeToExec;
        const int _gradeToSign;
        bool _isSigned;
    public:
        AForm();
        AForm(const AForm& other);
        AForm(std::string name, int gradeToSign, int gradeToExec);
        AForm& operator=(const AForm& other);
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class NotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        void beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm();
    protected:
        void checkExecution(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& out, const AForm& f);
