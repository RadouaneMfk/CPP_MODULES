#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // test of subject:
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // delete j; //should not create a leak
    // delete i;

    size_t size = 10;
    Animal *arr[size];

    for (size_t i = 0; i < size / 2; i++)
        arr[i] = new Cat();
    
    for (size_t i = size / 2; i < size; i++)
        arr[i] = new Dog();

    for (size_t i = 0; i < size; i++)
    {
        delete arr[i];
    }
}
