#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // Test 1: valid form creation
    try {
        Form f("TaxForm", 50, 25);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 2: form with grade too high (0 or negative)
    try {
        Form f("BadForm", 0, 25);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 3: form with grade too low (above 150)
    try {
        Form f("BadForm", 50, 151);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 4: bureaucrat grade high enough to sign
    try {
        Bureaucrat b("Alice", 40);
        Form f("TaxForm", 50, 25);
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 5: bureaucrat grade too low to sign
    try {
        Bureaucrat b("Bob", 100);
        Form f("TaxForm", 50, 25);
        b.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test 6: signing already signed form
    try {
        Bureaucrat b("Alice", 1);
        Form f("TaxForm", 50, 25);
        b.signForm(f);
        b.signForm(f); // sign again
        std::cout << f << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
