#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("ghost") {
    std::cout << "ShrubberyCreationForm default constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm parammeterized constructor called.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called.\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other)
        _target = other._target;
    std::cout << "ShrubberyCreationForm copy assignement operator called.\n";
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called.\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open()) {
        std::cerr << "oufile open error!\n";
        return;
    }
    outfile 
    << "  *\n" 
    << " ***\n" 
    << "*****\n"
    << "  |\n";
    outfile.close();
}
