#include "Character.hpp"

Character::Character() : name("ghost") {
    if (DEBUG)
        std::cout << "character default constructor called\n";
    for (size_t i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

Character::Character(std::string name) : name(name) {
    if (DEBUG)
        std::cout << "character parammetrized constructor called\n";
    for (size_t i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

Character::~Character() {
    if (DEBUG)
        std::cout << "character destructor called\n";
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materias[i])
            delete this->materias[i];
    }
}

std::string const& Character::getName() const {
    return this->name;
}

Character::Character(const Character& other) {
    if (DEBUG)
        std::cout << "Character copy constructor called\n";
    this->name = other.name;
    for (size_t i = 0; i < 4; i++)
    {
        if (other.materias[i])
            this->materias[i] = other.materias[i]->clone();
        else
            this->materias[i] = NULL;
    }
}

Character& Character::operator=(const Character& other) {
    if (DEBUG)
        std::cout << "Character copy assignment operator called\n";
    this->name = other.name;
    for (size_t i = 0; i < 4; i++)
        delete this->materias[i];
    for (size_t i = 0; i < 4; i++)
        this->materias[i] = other.materias[i]->clone();
    return *this;
}

void Character::equip(AMateria *m) {
    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materias[i] == m)
            return;
        if (this->materias[i] == NULL) {
            this->materias[i] = m;
            return;
        }
    }
    return;
}

void Character::unequip(int idx) {
    if (idx < 0 || idx > 3)
        return;
    if (this->materias[idx] == NULL)
        return;
    if (this->materias[idx])
    {
        Floor::dropMateria(this->materias[idx]);
        this->materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    if (idx < 0 || idx > 3)
        return;
    if (this->materias[idx] == NULL)
        return;
    this->materias[idx]->use(target);
}
