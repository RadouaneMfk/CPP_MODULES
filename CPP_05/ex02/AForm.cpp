#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("ghost"), _gradeToExec(75), _gradeToSign(75), _isSigned(false) {
    std::cout << "Form " << getName() << " default constructor called!\n";
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name), _gradeToExec(gradeToExec), _gradeToSign(gradeToSign) {
    _isSigned = false;
    if (_gradeToExec < 1 || _gradeToSign < 1)
        throw GradeTooHighException();
    if (_gradeToExec > 150 || _gradeToSign > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << getName() << " parammeterized constructor called!\n";
}

AForm::AForm(const AForm& other): _name(other._name), _gradeToExec(other._gradeToExec), _gradeToSign(other._gradeToSign), _isSigned(other._isSigned) {
    std::cout << "AForm " << getName() << " copy constructor called!\n";
}

AForm& AForm::operator=(const AForm& other) {
    _isSigned = other._isSigned;
    std::cout << "AForm " << getName() << " copy assignement operator called!\n";
    return *this;
}

const std::string AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExec() const {
    return _gradeToExec;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is Too High!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is Too Low!";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form not signed!";
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > getGradeToSign())
        throw GradeTooLowException();
    _isSigned = true;
}

AForm::~AForm() {
    std::cout << "AForm " << getName() << " destructor called!\n";
}

void AForm::checkExecution(Bureaucrat const& executor) const {
    if (this->getIsSigned() == false)
        throw NotSignedException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << f.getName() << ", signed: " << f.getIsSigned()
    << ", grade to sign: " << f.getGradeToSign() << ", grade to exec: "
    << f.getGradeToExec();
    return out;
}
