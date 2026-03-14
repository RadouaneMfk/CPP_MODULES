#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *brain;
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void setType(std::string type);
        std::string getType(void) const;
        void makeSound() const;
        ~Cat();
};
