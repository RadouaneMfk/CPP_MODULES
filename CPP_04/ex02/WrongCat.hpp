#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat& operator=(const WrongCat& other);
        void setType(std::string type);
        std::string getType(void) const;
        void makeSound() const;
        ~WrongCat();
};
