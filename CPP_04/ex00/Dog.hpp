#pragma once

#include "Animal.hpp"

class Dog : public Animal {
    public:
        Dog();
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        void setType(std::string type);
        std::string getType() const;
        void makeSound() const;
        ~Dog();
};
