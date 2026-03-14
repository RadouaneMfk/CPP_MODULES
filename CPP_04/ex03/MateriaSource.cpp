#include "MateriaSource.hpp"
#include "Floor.hpp"

MateriaSource::MateriaSource() {
    if (DEBUG)
        std::cout << "MateriaSource default constructor called\n";
    for (size_t i = 0; i < 4; i++)
        this->materiasList[i] = NULL;
}

MateriaSource::~MateriaSource() {
    if (DEBUG)
        std::cout << "MateriaSource destructor called\n";
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materiasList[i])
            delete this->materiasList[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    if (DEBUG)
        std::cout << "MateriaSource copy constructor called\n";
    for (size_t i = 0; i < 4; i++)
        this->materiasList[i] = other.materiasList[i]->clone();
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (DEBUG)
        std::cout << "MateriaSource copy assignement operator called\n";
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materiasList[i])
            delete this->materiasList[i];
    }
    for (size_t i = 0; i < 4; i++)
        this->materiasList[i] = other.materiasList[i]->clone();
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    if (!m)
        return;
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materiasList[i] == NULL) {
            this->materiasList[i] = m->clone();
            delete m;
            return;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (size_t i = 0; i < 4; i++)
    {
        if (this->materiasList[i] != NULL)
        {
            if (this->materiasList[i]->getType() == type)
                return this->materiasList[i]->clone();
        }
    }
    return 0;
}
