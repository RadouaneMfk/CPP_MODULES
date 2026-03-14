#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define DEBUG 0

class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(const AMateria& other);
        AMateria(std::string const & type);
        AMateria& operator=(const AMateria& other);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
        virtual ~AMateria();
};
