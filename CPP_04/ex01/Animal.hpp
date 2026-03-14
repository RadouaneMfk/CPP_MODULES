#pragma once

#include <string>
#include <iostream>

class Animal {
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal& other);
        Animal& operator=(const Animal& other);
        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual ~Animal();
};
