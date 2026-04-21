#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called.\n";
}

Intern::Intern(const Intern& other) {
    *this = other;
    std::cout << "Intern copy constructor called.\n";
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern copy assignement operator called.\n";
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called.\n";
}

struct formCreator {
    std::string name;
    AForm* (*create)(std::string target);
};

AForm* createShrubbery(std::string target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(std::string target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget) {
    formCreator forms[] = {
        {"shrubbery creation", createShrubbery},
        {"robotomy request", createRobotomy},
        {"presidential pardon", createPresidential},
    };

    for (size_t i = 0; i < 3; i++)
    {
        if (forms[i].name == formName) {
            std::cout << "Intern created " << formName << ".\n";
            return (forms[i].create(formTarget));
        }
    }
    std::cerr << "Form " << formName << " doesn't exist!\n";
    return NULL;
}
