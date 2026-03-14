#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    // test for animal
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    // test for wrong Animal
    // const WrongAnimal *meta = new WrongAnimal();
    // const WrongAnimal *i = new WrongCat();
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); // will output the WrongAnimal sound!
    // meta->makeSound();
    return 0;
}
