#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("ghost"), _isSigned(false), _gradeToExec(75), _gradeToSign(75) {
    std::cout << "Form " << getName() << " default constructor called!\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign) {
    _isSigned = false;
    if (_gradeToExec < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExec > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
    std::cout << "Form " << getName() << " parammeterized constructor called!\n";
}

Form::Form(const Form& other): _name(other._name), _isSigned(other._isSigned), _gradeToExec(other._gradeToExec), _gradeToSign(other._gradeToSign) {
    std::cout << "Form " << getName() << " copy constructor called!\n";
}

Form& Form::operator=(const Form& other) {
    _isSigned = other._isSigned;
    std::cout << "Form " << getName() << " copy assignement operator called!\n";
    return *this;
}

const std::string Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExec() const {
    return _gradeToExec;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is Too High!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is Too Low!";
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    _isSigned = true;
}

Form::~Form() {
    std::cout << "Form " << getName() << " destructor called!\n";
}

std::ostream& operator<<(std::ostream& out, Form& f) {
    out << f.getName() << ", signed: " << f.getIsSigned()
    << ", grade to sign: " << f.getGradeToSign() << ", grade to exec: "
    << f.getGradeToExec();
    return out;
}