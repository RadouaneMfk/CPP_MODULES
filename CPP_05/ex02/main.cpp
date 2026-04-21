#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    // Test 1: ShrubberyCreationForm - valid execution
    try {
        Bureaucrat b("Alice", 1);
        ShrubberyCreationForm f("home");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 2: Execute without signing
    try {
        Bureaucrat b("Bob", 1);
        ShrubberyCreationForm f("garden");
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 3: Executor grade too low
    try {
        Bureaucrat b("Alice", 1);
        Bureaucrat c("Charlie", 140);
        ShrubberyCreationForm f("park");
        b.signForm(f);
        c.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 4: RobotomyRequestForm - valid execution
    try {
        Bureaucrat b("Alice", 1);
        RobotomyRequestForm f("Bender");
        b.signForm(f);
        b.executeForm(f);
        b.executeForm(f); // run twice to see 50/50
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 5: PresidentialPardonForm - valid execution
    try {
        Bureaucrat b("Alice", 1);
        PresidentialPardonForm f("Marvin");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 6: PresidentialPardonForm - grade too low to sign
    try {
        Bureaucrat b("Bob", 50);
        PresidentialPardonForm f("Marvin");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}