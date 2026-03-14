#pragma once

#include "AMateria.hpp"

class Floor {
    private:
        struct node {
            AMateria* AMateria;
            node* next;
        };
        static node* head;
        struct Clean {
            ~Clean();
        };
        static Clean clean;
    public:
        Floor();
        Floor(const Floor& other);
        Floor& operator=(const Floor& other);
        static void dropMateria(AMateria* m);
        static void clearList();
        ~Floor();
};
