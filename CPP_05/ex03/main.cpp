#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someIntern;

    // Test 1: valid shrubbery creation
    AForm* form1 = someIntern.makeForm("shrubbery creation", "home");
    if (form1) {
        Bureaucrat b("Alice", 1);
        b.signForm(*form1);
        b.executeForm(*form1);
        delete form1;
    }

    // Test 2: valid robotomy request
    AForm* form2 = someIntern.makeForm("robotomy request", "Bender");
    if (form2) {
        Bureaucrat b("Alice", 1);
        b.signForm(*form2);
        b.executeForm(*form2);
        b.executeForm(*form2);
        b.executeForm(*form2);
        delete form2;
    }

    // Test 3: valid presidential pardon
    AForm* form3 = someIntern.makeForm("presidential pardon", "Marvin");
    if (form3) {
        Bureaucrat b("Alice", 1);
        b.signForm(*form3);
        b.executeForm(*form3);
        delete form3;
    }

    // Test 4: invalid form name
    AForm* form4 = someIntern.makeForm("coffee request", "Bob");
    if (form4)
        delete form4;

    return 0;
}