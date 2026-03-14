#include "Floor.hpp"

Floor::node* Floor::head = NULL;
Floor::Clean Floor::clean;

Floor::Floor() {
    if (DEBUG)
        std::cout << "Floor constructor called\n";
}

Floor::Floor(const Floor& other) {
    if (DEBUG)
        std::cout << "Floor copy constructor called\n";
    (void)other;
}

Floor::~Floor() {
    if (DEBUG)
        std::cout << "Floor destructor called\n";
}

Floor& Floor::operator=(const Floor& other) {
    (void)other;
    return *this;
}

void Floor::dropMateria(AMateria* m) {
    if (!m)
        return;
    node* newNode = new node;
    newNode->AMateria = m;
    newNode->next = head;
    head = newNode;
}

void Floor::clearList() {
    node* tmp;

    while (head)
    {
        tmp = head;
        head = head->next;
        delete tmp->AMateria;
        delete tmp;
    }
}

Floor::Clean::~Clean() {
    Floor::clearList();
}