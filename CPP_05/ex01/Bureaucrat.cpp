#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("ghost"), grade(75) {
    std::cout << "Bureaucrat " << getName() << " default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat " << getName() << " parammetrized constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    *this = other;
    std::cout << "Bureaucrat " << this->getName() << " copy constructor called\n";
}

std::string Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		grade = other.grade;
    std::cout << "Bureaucrat " << this->getName() << " copy assignement operator called\n";
    return *this;
}

void Bureaucrat::incrementGrade() {
	this->grade--;
    if (this->grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
    if (this->grade > 150)
        throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is Too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is Too Low";
}

void Bureaucrat::signForm(Form& f) {
    try
    {
        if (f.getIsSigned() == true)
            return;
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getName() << ".\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << " couldn’t sign " << f.getName() << " because "
        << e.what() << ".\n";
    }
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << this->getName() << " destructor called\n";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return out;
}
