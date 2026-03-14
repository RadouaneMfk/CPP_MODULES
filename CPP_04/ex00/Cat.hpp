#pragma once

#include "Animal.hpp"

class Cat : public Animal {
    public:
        Cat();
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        void setType(std::string type);
        std::string getType(void) const;
        void makeSound() const;
        ~Cat();
};
