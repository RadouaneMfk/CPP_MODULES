#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("ghost") {
    std::cout << "RobotomyRequestForm default constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm parammeterized constructor called.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called.\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other)
        _target = other._target;
    std::cout << "RobotomyRequestForm copy assignement operator called.\n";
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called.\n";
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    std::cout << "RRRRRRR......RRRRRRRRR.....\n";
    std::srand(time(0));
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfull.\n";
    else
        std::cout << _target << " robotomy failed.\n";
}
