#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToExec;
        const int _gradeToSign;
    public:
        Form();
        Form(const Form& other);
        Form(std::string name, int gradeToSign, int gradeToExec);
        Form& operator=(const Form& other);
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        const std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;
        void beSigned(const Bureaucrat& b);
        ~Form();
};

std::ostream& operator<<(std::ostream& out, Form& f);